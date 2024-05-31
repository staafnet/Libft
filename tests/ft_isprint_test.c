/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:13:07 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/05 08:33:19 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_isprint_unit_test(void)
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
		if (ft_isprint(a))
			printf(COLOR_BLUE "This is a printable character -> "
				COLOR_RESET "%c\n", a);
		else
			printf(COLOR_BLUE "This is NOT a printable character (ASCII) -> "
				COLOR_RESET "%d\n", a);
	}
}

void	ft_isprint_test(void)
{
	int		c;
	size_t	i;

	c = -300;
	i = 0;
	while (c <= 300)
	{
		if (isprint(c) != ft_isprint(c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n"
				COLOR_RESET, isprint(c), ft_isprint(c));
			return ;
		}
		c++;
		i++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%ld\n" COLOR_RESET, i);
	ft_isprint_unit_test();
}
