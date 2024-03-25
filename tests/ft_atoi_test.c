#include "../libft.h"

void ft_atoi_test(void)
{
	printf(COLOR_BLUE "Testing ft_atoi:\n" COLOR_RESET);

	char *test_cases[] = {
		"123",
		"   -456",
		"789 test",
		"0",
		"-2147483648",
		"2147483647",
		"",
		"   ",
		"abc123",
		"-abc456",
		"-+42",
		"+-42",
		"+42lyon",
		"+101",
		"2147483648",
		"-2147483649",
		"+42",
		"-42",
		"1",
		"-1"};

	int i = 0;
	int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);
	int success = 1;

	while (i < num_test_cases)
	{
		int result_ft = ft_atoi(test_cases[i]);
		int result_standard = atoi(test_cases[i]);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: Input: \"%s\", ft_atoi result: %d, atoi result: %d\n" COLOR_RESET, test_cases[i], result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
