#include "../libft.h"

void ft_isdigit_test(void)
{
	printf(COLOR_BLUE "Testing ft_isdigit:\n" COLOR_RESET);

	int success = 1;
	int i = 0;

	while (i <= 127)
	{
		int result_ft = ft_isdigit(i);
		int result_standard = isdigit(i);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: '%c' (%d), ft_isdigit result: %d, isdigit result: %d\n" COLOR_RESET, (isprint(i) ? i : '.'), i, result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
