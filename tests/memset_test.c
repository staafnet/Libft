/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:56:28 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/11 20:40:20 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset_test(void)
{
	char	str1[20];
	char	str2[20];
	int		arr1[5];
	int		arr2[5];

	ft_memset(str1, 'A', 10);
	memset(str2, 'A', 10);
	if (memcmp(str1, str2, 10) == 0)
		printf("T1: Passed\n");
	else
		printf("T1: Failed\n");

	ft_memset(str1, '\0', 5);
	memset(str2, '\0', 5);
	if (memcmp(str1, str2, 5) == 0)
		printf("T2: Passed\n");
	else
		printf("T2: Failed\n");

	ft_memset(arr1, 0, 5 * sizeof(int));
	memset(arr2, 0, 5 * sizeof(int));
	if (memcmp(arr1, arr2, 5 * sizeof(int)) == 0)
		printf("T3: Passed\n");
	else
		printf("T3: Failed\n");
}
