/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:29:50 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/05 13:07:18 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libft_tests.h"

int	generate_strings_length1(char *c)
{
	int	i;

	i = 0;
	while (i <= 127)
	{
		c[0] = i;
		c[1] = '\0';
		if (strlen(c) != ft_strlen(c))
			return (0);
		i++;
	}
	return (i);
}

int	generate_strings_length2(char *c)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	while (i <= 127)
	{
		j = 0;
		while (j <= 127)
		{
			c[0] = i;
			c[1] = j;
			c[2] = '\0';
			if (strlen(c) != ft_strlen(c))
				return (0);
			j++;
			t++;
		}
		i++;
	}
	return (t);
}

int	generate_strings_length3(char *c)
{
	int	i;
	int	j;
	int	k;
	int	t;

	i = 0;
	t = 0;
	while (i <= 127)
	{
		j = 0;
		while (j <= 127)
		{
			k = 0;
			while (k <= 127)
			{
				c[0] = i;
				c[1] = j;
				c[2] = k;
				c[3] = '\0';
				if (strlen(c) != ft_strlen(c))
					return (0);
				k++;
				t++;
			}
			j++;
		}
		i++;
	}
	return (t);
}

int	ft_norminette(char *directory, char *file_name, char *function_name)
{
	FILE	*fp;
	char	command[256];
	char	line[256];

	printf(COLOR_GRAY "\n--- %s ---" COLOR_RED "\n", function_name);
	sprintf(command, "norminette %s/%s", directory, file_name);
	fp = popen(command, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	fgets(line, sizeof(line), fp);
	pclose(fp);
	if (strstr(line, ": OK!") != NULL)
	{
		printf(COLOR_GRAY "norminette:  " COLOR_LIGHT_GREEN "OK\n" COLOR_RESET);
		return (1);
	}
	else
	{
		printf(COLOR_RED);
		system(command);
		printf(COLOR_RESET);
		return (0);
	}
}

void	ft_test_function(const char *function_name)
{
	if (strcmp(function_name, "ft_isalpha") == 0)
		ft_isalpha_test();
	if (strcmp(function_name, "ft_isdigit") == 0)
		ft_isdigit_test();
	if (strcmp(function_name, "ft_isalnum") == 0)
		ft_isalnum_test();
	if (strcmp(function_name, "ft_isascii") == 0)
		ft_isascii_test();
	if (strcmp(function_name, "ft_isprint") == 0)
		ft_isprint_test();
	if (strcmp(function_name, "ft_tolower") == 0)
		ft_tolower_test();
	if (strcmp(function_name, "ft_toupper") == 0)
		ft_toupper_test();
	if (strcmp(function_name, "ft_strlen") == 0)
		ft_strlen_test();
}

void	ft_test_files(char *directory)
{
	DIR				*dir;
	struct dirent	*entry;
	char			function_name[256];

	dir = opendir(directory);
	if (dir == NULL)
		exit(EXIT_FAILURE);
	while ((entry = readdir(dir)) != NULL)
	{
		if (strlen(entry->d_name) < 2 || strncmp(entry->d_name, "ft_", 3) != 0)
			continue ;

		strncpy(function_name, entry->d_name, sizeof(function_name) - 1);
		function_name[sizeof(function_name) - 1] = '\0';

		function_name[strlen(function_name) - 2] = '\0';

		if (ft_norminette(directory, entry->d_name, function_name))
			ft_test_function(function_name);
	}
	closedir(dir);
}

int	main(void)
{
	ft_test_files(".");
	ft_test_files("./bonus");
	return (0);
}
