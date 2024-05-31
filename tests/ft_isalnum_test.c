/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:49:29 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/04 19:58:00 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_isalnum_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (ft_isalnum(a))
			printf(COLOR_BLUE "This is alphanumeric -> " COLOR_RESET "%c\n", a);
		else if (a == '\n')
			return ;
		else
			printf(COLOR_BLUE "This is NOT alphanumeric (ASCII) -> "
				COLOR_RESET "%d\n", a);
	}
}

void	ft_isalnum_test(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (isalnum(c) != ft_isalnum(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, isalnum(c), ft_isalnum(c));
			return ;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_isalnum_unit_test();
}
