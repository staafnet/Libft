#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dst;
	unsigned char *source;
	size_t i;

	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}