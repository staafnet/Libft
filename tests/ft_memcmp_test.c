#include "../libft.h"

void ft_memcmp_test(void)
{
	printf(COLOR_BLUE "Testing ft_memcmp:\n" COLOR_RESET);

	char *str1 = "hello";
	char *str2 = "hello";
	char *str3 = "helo";
	size_t n = 5;

	// Test 1: Porównanie dwóch identycznych ciągów znaków
	int result_ft_1 = ft_memcmp(str1, str2, n);
	int result_std_1 = memcmp(str1, str2, n);

	if (result_ft_1 == result_std_1)
		printf(COLOR_GREEN "Test 1 passed: ft_memcmp result: %d, memcmp result: %d\n" COLOR_RESET, result_ft_1, result_std_1);
	else
		printf(COLOR_RED "Test 1 failed: ft_memcmp result: %d, memcmp result: %d\n" COLOR_RESET, result_ft_1, result_std_1);

	// Test 2: Porównanie dwóch różnych ciągów znaków
	int result_ft_2 = ft_memcmp(str1, str3, n);
	int result_std_2 = memcmp(str1, str3, n);

	if (result_ft_2 == result_std_2)
		printf(COLOR_GREEN "Test 2 passed: ft_memcmp result: %d, memcmp result: %d\n" COLOR_RESET, result_ft_2, result_std_2);
	else
		printf(COLOR_RED "Test 2 failed: ft_memcmp result: %d, memcmp result: %d\n" COLOR_RESET, result_ft_2, result_std_2);
}

int main(void)
{
	ft_memcmp_test();
	return 0;
}
