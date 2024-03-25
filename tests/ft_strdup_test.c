#include "../libft.h"

void ft_strdup_test(void)
{
	printf(COLOR_BLUE "Testing ft_strdup:\n" COLOR_RESET);
	int success = 1;

	// Test 1: Kopiowanie niepustego ciągu znaków
	char str1[] = "Hello, World!";
	char *result1 = ft_strdup(str1);
	char *expected1 = strdup(str1);
	if (strcmp(result1, expected1) != 0)
	{
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);
		success = 0;
	}
	free(result1);
	free(expected1);

	// Test 2: Kopiowanie pustego ciągu znaków
	char str2[] = "";
	char *result2 = ft_strdup(str2);
	char *expected2 = strdup(str2);
	if (strcmp(result2, expected2) != 0)
	{
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);
		success = 0;
	}
	free(result2);
	free(expected2);

	if (success)
		printf(COLOR_GREEN "All tests passed!\n" COLOR_RESET);
}