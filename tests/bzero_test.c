/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:04:00 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/11 21:15:58 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero_test(void)
{
	char str1[] = "Hello, World!";
	printf("Before bzero (string): %s\n", str1);
	ft_bzero(str1, 5);
	printf("After bzero: %s\n", str1);

	int arr[] = {1, 2, 3, 4, 5};
	printf("Before bzero (int array): {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	ft_bzero(arr, 3 * sizeof(int));
	printf("After bzero: {%d, %d, %d, %d, %d}\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

	float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	printf("Before bzero (float array): {%f, %f, %f, %f, %f}\n", floatArr[0], floatArr[1], floatArr[2], floatArr[3], floatArr[4]);
	ft_bzero(floatArr, 2 * sizeof(float));
	printf("After bzero: {%f, %f, %f, %f, %f}\n", floatArr[0], floatArr[1], floatArr[2], floatArr[3], floatArr[4]);

	char charArr[] = {'a', 'b', 'c', 'd', 'e'};
	printf("Before bzero (char array): {%c, %c, %c, %c, %c}\n", charArr[0], charArr[1], charArr[2], charArr[3], charArr[4]);
	ft_bzero(charArr, sizeof(charArr));
	printf("After bzero: {%c, %c, %c, %c, %c}\n", charArr[0], charArr[1], charArr[2], charArr[3], charArr[4]);
}
