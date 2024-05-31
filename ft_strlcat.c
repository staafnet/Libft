/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:14:48 by rgrochow          #+#    #+#             */
/*   Updated: 2024/03/27 21:14:49 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t srclen = ft_strlen(src);
	size_t dstlen = ft_strlen(dst);
	size_t total_len = srclen + dstlen;
	if (dstsize <= dstlen)
		return srclen + dstsize;
	ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return total_len;
}