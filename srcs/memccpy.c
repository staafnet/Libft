/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:05:40 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/12 21:13:03 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		if (src_ptr[i] == (unsigned char)c)
		{
			dst_ptr[i + 1] = '\0'; // Dodaj terminator null po skopiowanych danych
			return ((void *)&dst_ptr[i + 1]);
		}
		i++;
	}
	return (NULL);
}
