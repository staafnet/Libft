/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:58 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/04 19:05:55 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_tolower_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (a != '\n')
			printf(COLOR_BLUE"Result ->"COLOR_RESET" %c\n", ft_tolower(a));
	}
}

void	ft_tolower_test(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (tolower(c) != ft_tolower(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, tolower(c), ft_tolower(c));
			return ;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_tolower_unit_test();
}
