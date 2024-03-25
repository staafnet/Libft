
#include "../libft.h"

void ft_isalpha_test(void)
{
	printf(COLOR_BLUE "Testing ft_isalpha:\n" COLOR_RESET);

	int success = 1; // Flag indicating whether all tests passed successfully

	int c = 0;
	while (c <= 127)
	{
		int result_ft = ft_isalpha(c);
		int result_standard = isalpha(c);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: '%c' (%d), ft_isalpha result: %d, isalpha result: %d\n" COLOR_RESET, (isprint(c) ? c : '.'), c, result_ft, result_standard);
			success = 0;
		}

		c++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
