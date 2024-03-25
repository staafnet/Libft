#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t s_len = 0;
	size_t i;

	if (!s)
		return (NULL);

	while (s[s_len])
		s_len++;

	if (start > s_len)
		return (NULL);

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);

	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';

	return (substr);
}
