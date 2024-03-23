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