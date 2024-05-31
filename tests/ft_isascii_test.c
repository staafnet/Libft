/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:22:46 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/04 20:58:42 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_isascii_unit_test(void)
{
	char	a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return ;
		if (a == '\n')
			return ;
		if (ft_isascii(a))
			printf(COLOR_BLUE "This is an ASCII character -> "
				COLOR_RESET "%c\n", a);
		else
			printf(COLOR_BLUE "This is NOT an ASCII character (non-ASCII) -> "
				COLOR_RESET "%d\n", a);
	}
}

void	ft_isascii_test(void)
{
	int		c;
	size_t	i;

	c = -300;
	i = 0;
	while (c <= 300)
	{
		if (isascii(c) != ft_isascii(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, isascii(c), ft_isascii(c));
			return ;
		}
		c++;
		i++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%ld\n" COLOR_RESET, i);
	ft_isascii_unit_test();
}
