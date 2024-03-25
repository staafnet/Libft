#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	int length = 0;
	while (s[length])
		length++;
	write(fd, s, length);
}
