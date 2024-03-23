#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr = s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (void *)ptr;
		ptr++;
	}
	return NULL;
}