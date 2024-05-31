/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:27 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/04 19:17:38 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_isdigit_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (ft_isdigit(a))
			printf(COLOR_BLUE "This is a number -> "
				COLOR_RESET "%c\n", a);
		else if (a == '\n')
			return ;
		else
			printf(COLOR_BLUE "This is NOT a number (ASCII) -> "
				COLOR_RESET "%d\n", a);
	}
}

void	ft_isdigit_test(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (isdigit(c) != ft_isdigit(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, isdigit(c), ft_isdigit(c));
			return ;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_isdigit_unit_test();
}
