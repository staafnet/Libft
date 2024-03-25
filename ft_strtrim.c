#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char *trimmed;
	size_t len_s1 = 0;
	size_t start = 0;
	size_t end = 0;
	size_t i = 0;

	if (!s1 || !set)
		return NULL;
	while (s1[len_s1])
		len_s1++;
	while (s1[start])
	{
		int found = 0;
		for (size_t j = 0; set[j]; j++)
		{
			if (s1[start] == set[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		start++;
	}
	end = len_s1;
	while (end > start)
	{
		int found = 0;
		for (size_t j = 0; set[j]; j++)
		{
			if (s1[end - 1] == set[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		end--;
	}
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return NULL;

	for (i = 0; start < end; i++, start++)
		trimmed[i] = s1[start];
	trimmed[i] = '\0';
	return trimmed;
}
