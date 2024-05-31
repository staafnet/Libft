/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:43:52 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/05 13:58:45 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "libft_tests.h"

void ft_strlen_unit_test(void)
{
	char a[256];
	int i = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	scanf("%s", a);
	while (a[i] != '\n')
	{
		printf(COLOR_BLUE "Result ->" COLOR_RESET " %zu\n", ft_strlen(a));
		i++;
	}
}

void ft_strlen_test(void)
{
	char c[11];
	int i;

	i = generate_strings_length1(c);
	i += generate_strings_length2(c);
	i += generate_strings_length3(c);
	if (i > 0)
	{
		printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, i);
	}
	else
	{
		printf(COLOR_RED "Test failed: Input: %s\n", c);
		printf("Expected: %zu, Result: %zu\n" COLOR_RESET, strlen(c), ft_strlen(c));
	}
	ft_strlen_unit_test();
}
