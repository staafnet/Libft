#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen = ft_strlen(src);
	size_t minlen = (dstsize > 0) ? (dstsize - 1) : 0;
	size_t cpylen = (srclen < minlen) ? srclen : minlen;
	ft_memcpy(dst, src, cpylen);
	dst[cpylen] = '\0';
	return srclen;
}