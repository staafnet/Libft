#include "../libft.h"

void ft_toupper_test(void)
{
	printf(COLOR_BLUE "Testing ft_toupper:\n" COLOR_RESET);

	int success = 1;
	int i = 0;
	while (i <= 127)
	{
		int result_ft = ft_toupper(i);
		int result_standard = toupper(i);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: '%c' (%d), ft_toupper result: %d, toupper result: %d\n" COLOR_RESET, (isprint(i) ? i : '.'), i, result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
