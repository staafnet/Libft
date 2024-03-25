#include "../libft.h"

void print_split_result(char **result)
{
	if (result)
	{
		while (*result)
		{
			printf("%s\n", *result);
			result++;
		}
	}
	else
	{
		printf("NULL\n");
	}
}

void ft_split_test(void)
{
	printf("Testing ft_split:\n");

	// Test case 1: Podstawowy test
	printf("Test case: Podstawowy test\n");
	char **result1 = ft_split("Hello World", ' ');
	printf("Result:\n");
	print_split_result(result1);
	printf("----------\n");
	// Zwolnij pamięć zaalokowaną przez ft_split
	char **tmp1 = result1;
	while (*tmp1)
	{
		free(*tmp1);
		tmp1++;
	}
	free(result1);

	// Test case 2: Pusty ciąg znaków
	printf("Test case: Pusty ciąg znaków\n");
	char **result2 = ft_split("", ' ');
	printf("Result:\n");
	print_split_result(result2);
	printf("----------\n");
	// Zwolnij pamięć zaalokowaną przez ft_split
	free(result2);

	// Dodaj więcej testów dla różnych przypadków...
}