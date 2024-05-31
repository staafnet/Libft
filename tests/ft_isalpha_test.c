/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:28:03 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/04 19:00:19 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_isalpha_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (ft_isalpha(a))
			printf(COLOR_BLUE "This is a letter of the alphabet -> "
				COLOR_RESET "%c\n", a);
		else if (a == '\n')
			return ;
		else
			printf(COLOR_BLUE "This is NOT a letter of the alphabet (ASCII) -> "
				COLOR_RESET "%d\n", a);
	}
}

void	ft_isalpha_test(void)
{
	int		c;

	c = 0;
	while (c <= 127)
	{
		if (isalpha(c) != ft_isalpha(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, isalpha(c), ft_isalpha(c));
			return ;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_isalpha_unit_test();
}
