#include "../libft.h"

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_itoa_test(void)
{
	printf(COLOR_BLUE "Testing ft_itoa:\n" COLOR_RESET);

	int success = 1;
	int num_test_cases = 9;
	int test_cases[] = {0, -12345, 987654321, -2147483648, 2147483647, 42, 'a', '*', ' '};
	char *expected_results[] = {"0", "-12345", "987654321", "-2147483648", "2147483647", "42", NULL, NULL, NULL};

	int i = 0;
	while (i < num_test_cases)
	{
		int n = test_cases[i];
		char *result_ft = ft_itoa(n);
		char result_std[12]; // 12 to maksymalna długość dla int + 1 na null terminator

		sprintf(result_std, "%d", n);

		if ((expected_results[i] == NULL && (result_ft != NULL)) ||
			(expected_results[i] != NULL && (strcmp(result_ft, expected_results[i]) != 0 || strcmp(result_std, expected_results[i]) != 0)))
		{
			printf(COLOR_RED "Test failed: Input: %d, ft_itoa result: %s, sprintf result: %s\n" COLOR_RESET, n, result_ft, result_std);
			success = 0;
		}

		free(result_ft);

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
