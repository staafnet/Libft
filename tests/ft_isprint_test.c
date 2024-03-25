#include "../libft.h"

void ft_isprint_test(void)
{
	printf(COLOR_BLUE "Testing ft_isprint:\n" COLOR_RESET);

	int success = 1;
	int i = -200;
	while (i <= 200)
	{
		int result_ft = ft_isprint(i);
		int result_standard = isprint(i);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: '%c' (%d), ft_isprint result: %d, isprint result: %d\n" COLOR_RESET, (isprint(i) ? i : '.'), i, result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
