/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:24:11 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/22 12:43:10 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_memcpy_test(void)
{
	char	src[14];
	char	dest[14];
	char	dest_memcpy[14];

	strcpy(src, "Hello, World!");
	ft_memcpy(dest, src, strlen(src) + 1);
	memcpy(dest_memcpy, src, strlen(src) + 1);
	if (strcmp(dest, src) == 0)
		printf("\033[0;32mft_memcpy test passed: copied successfully\033[0m\n");
	else
		printf("\033[0;31mft_memcpy test failed: copy failed\033[0m\n");
	if (memcmp(dest, dest_memcpy, sizeof(dest)) == 0)
		printf("\033[0;32mmemcpy test passed: copied successfully\033[0m\n");
	else
		printf("\033[0;31mmemcpy test failed: copy failed\033[0m\n");
}