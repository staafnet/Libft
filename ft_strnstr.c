#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needle_len = 0;
	const char *ptr = haystack;

	while (needle[needle_len])
		needle_len++;


	if (needle_len == 0)
		return (char *)haystack;

	while (*ptr && len >= needle_len)
	{
		size_t i = 0;
		while (i < needle_len && haystack[i] == needle[i])
			i++;
		if (i == needle_len)
			return (char *)ptr;
		ptr++;
		len--;
	}

	return NULL;
}
