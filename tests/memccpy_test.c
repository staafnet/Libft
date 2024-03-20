/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:09:10 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/12 21:10:05 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_memccpy_test(void)
{
	char src[20];
	char dest1[20];
	char dest2[20];
	char *ptr1;
	char *ptr2;

	strcpy(src, "Hello, World!");

	ptr1 = ft_memccpy(dest1, src, 'o', strlen(src) + 1);
	ptr2 = memccpy(dest2, src, 'o', strlen(src) + 1);

	if ((ptr1 == NULL && ptr2 == NULL) || (ptr1 == dest1 && ptr2 == dest2 && strcmp(dest1, dest2) == 0))
	{
		printf("ft_memccpy test passed: copied successfully\n");
	}
	else
	{
		printf("ft_memccpy test failed: copy failed\n");
		printf("Expected: %s\n", dest2);
		printf("Received: %s\n", dest1);
	}
}