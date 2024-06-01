/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:42:44 by rgrochow          #+#    #+#             */
/*   Updated: 2024/05/31 21:52:51 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (dst == NULL)
		return (NULL);
	if (src == NULL || len == 0)
		return (dst);
	if (dst == src)
		return (dst);
	cdst = dst;
	csrc = (char *)src;
	if (src < dst)
	{
		csrc += len;
		cdst += len;
		while (len--)
		{
			*--cdst = *--csrc;
		}
	}
	else
		while (len--)
			*cdst++ = *csrc++;
	return (dst);
}
