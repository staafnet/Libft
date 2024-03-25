#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *joined;
	size_t len_s1 = 0;
	size_t len_s2 = 0;
	size_t i = 0;
	size_t j = 0;

	if (!s1 || !s2)
		return (NULL);
	while (s1[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	joined = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!joined)
		return (NULL);

	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}

	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';

	return (joined);
}
