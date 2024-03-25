#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		*ptr++ = uc;
	}

	return (s);
}