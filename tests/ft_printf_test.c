/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:10:49 by rgrochow          #+#    #+#             */
/*   Updated: 2024/04/14 19:11:19 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_printf_unit_test(void)
{
	char a;

	a = 0;
	printf(COLOR_BLUE "Insert characters and press Enter: " COLOR_RESET);
	while (a != '\n')
	{
		if (scanf("%c", &a) == '\n')
			return;
		int result = ft_printf("%c", a);
		if (result > 0)
			printf(COLOR_BLUE "Result -> " COLOR_RESET "%c\n", a);
		else if (result == 0)
			printf(COLOR_RED "Error: ft_printf failed to print character\n" COLOR_RESET);
		else
			printf(COLOR_BLUE "Result -> " COLOR_RESET "%d\n", a);
	}
}

void ft_printf_test(void)
{
	int c;

	c = 0;
	while (c <= 127)
	{
		if (printf("%c", c) != ft_printf("%c", c))
		{
			printf(COLOR_RED "Test failed: Input: %c\n", c);
			printf("Expected: %d, Result: %d\n" COLOR_RESET, printf("%c", c), ft_printf("%c", c));
			return;
		}
		c++;
	}
	printf(COLOR_GRAY "Total tests: " COLOR_LIGHT_GREEN "%d\n" COLOR_RESET, c);
	ft_printf_unit_test();
}
