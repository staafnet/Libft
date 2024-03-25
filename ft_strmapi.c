#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *mapped;
	size_t len = 0;
	size_t i = 0;

	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	mapped = (char *)malloc(sizeof(char) * (len + 1));
	if (!mapped)
		return (NULL);
	while (i < len)
	{
		mapped[i] = f(i, s[i]);
		i++;
	}
	mapped[i] = '\0';

	return (mapped);
}