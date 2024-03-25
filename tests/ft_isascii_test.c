#include "../libft.h"

void ft_isascii_test(void)
{
	printf(COLOR_BLUE "Testing ft_isascii:\n" COLOR_RESET);

	int success = 1;
	int i = -200;
	while (i <= 200)
	{
		int result_ft = ft_isascii(i);
		int result_standard = isascii(i);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: '%c' (%d), ft_isascii result: %d, isascii result: %d\n" COLOR_RESET, (isprint(i) ? i : '.'), i, result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
