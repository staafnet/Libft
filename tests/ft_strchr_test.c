#include "../libft.h"

void ft_strchr_test(void)
{
	printf(COLOR_BLUE "Testing ft_strchr:\n" COLOR_RESET);
	int success = 1; // Ustawienie początkowej wartości sukcesu na 1

	// Test 1: Przeszukiwanie ciągu znaków, w którym znak jest obecny
	char str1[] = "Hello, World!";
	int c1 = 'W';
	char *result1 = ft_strchr(str1, c1);
	char *expected1 = strchr(str1, c1);
	if (result1 != expected1)
	{
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);
		success = 0; // Jeśli test nie powiedzie się, ustaw flagę sukcesu na 0
	}

	// Test 2: Przeszukiwanie ciągu znaków, w którym znak nie jest obecny
	char str2[] = "Hello, World!";
	int c2 = 'z';
	char *result2 = ft_strchr(str2, c2);
	char *expected2 = strchr(str2, c2);
	if (result2 != expected2)
	{
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);
		success = 0; // Jeśli test nie powiedzie się, ustaw flagę sukcesu na 0
	}

	// Test 3: Przeszukiwanie pustego ciągu znaków
	char str3[] = "";
	int c3 = 'A';
	char *result3 = ft_strchr(str3, c3);
	char *expected3 = strchr(str3, c3);
	if (result3 != expected3)
	{
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);
		success = 0; // Jeśli test nie powiedzie się, ustaw flagę sukcesu na 0
	}

	if (success)
		printf(COLOR_GREEN "All tests passed!\n" COLOR_RESET);
}