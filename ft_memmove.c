#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d = dst;
	const unsigned char *s = src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return dst;
}