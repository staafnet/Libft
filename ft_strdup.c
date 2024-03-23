#include "libft.h"

char *ft_strdup(const char *s1)
{
	size_t len = 0;
	while (s1[len])
		len++;
	char *dup = (char *)malloc(len + 1);
	if (!dup)
		return NULL;
	for (size_t i = 0; i < len; i++)
		dup[i] = s1[i];
	dup[len] = '\0';

	return dup;
}
