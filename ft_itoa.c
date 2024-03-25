#include "libft.h"

static size_t ft_num_digits(int n)
{
	size_t count = 0;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return count;
}

char *ft_itoa(int n)
{
	size_t len = ft_num_digits(n);
	char *str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		return NULL;
	}
	size_t i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	do
	{
		str[i++] = '0' + (n % 10);
		n /= 10;
	} while (n > 0);
	str[i] = '\0';
	size_t start = (str[0] == '-') ? 1 : 0;
	size_t end = len - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}

	return str;
}
