#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return;
	int length = 0;
	while (s[length])
		length++;
	write(fd, s, length);
	write(fd, "\n", 1);
}
