/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:28:56 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/14 18:31:37 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_toupper_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (a != '\n')
			printf(COLOR_BLUE "Result ->" COLOR_RESET " %c\n", ft_toupper(a));
	}
}

void	ft_toupper_test(void)
{
	int	c;

	c = 0;
	while (c <= 127)
	{
		if (toupper(c) != ft_toupper(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, toupper(c), ft_toupper(c));
			return ;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_toupper_unit_test();
}
