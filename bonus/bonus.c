/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:03 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/22 09:21:03 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	const unsigned char *src_ptr;
	size_t i;

	dest_ptr = dest;
	src_ptr = src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}

	return (dest);
}
