/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:27:15 by rgrochow          #+#    #+#             */
/*   Updated: 2024/05/31 18:29:01 by rgrochow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	total_len;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	total_len = srclen + dstlen;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
	return (total_len);
}
