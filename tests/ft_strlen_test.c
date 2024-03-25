#include "../libft.h"

void ft_strlen_test(void)
{
	printf(COLOR_BLUE "Testing ft_strlen:\n" COLOR_RESET);

	const char *test_strings[] = {
		"Hello",
		"Lorem ipsum dolor sit amet",
		"1234567890",
		"",
		"This is a test string with some special characters: !@#$%^&*()_+",
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
		NULL
	};

	int i = 0;
	int success = 1;

	while (test_strings[i])
	{
		size_t result_ft = ft_strlen(test_strings[i]);
		size_t result_standard = strlen(test_strings[i]);

		if (result_ft != result_standard)
		{
			printf(COLOR_RED "Test failed: String: \"%s\", ft_strlen result: %zu, strlen result: %zu\n" COLOR_RESET, test_strings[i], result_ft, result_standard);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
