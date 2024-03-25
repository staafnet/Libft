#include "../libft.h"

void ft_memset_test(void)
{
	printf(COLOR_BLUE "Testing ft_memset:\n" COLOR_RESET);

	char test_str1[20] = "Hello, world!";
	char test_str2[20] = "Hello, world!";
	size_t len = 0;

	int success = 1;

	while (len <= 20)
	{
		ft_memset(test_str1, '!', len);
		memset(test_str2, '!', len);

		if (memcmp(test_str1, test_str2, sizeof(test_str1)) != 0)
		{
			printf(COLOR_RED "Test failed: ft_memset did not match the behavior of memset for first %zu bytes\n" COLOR_RESET, len);
			success = 0;
		}

		len++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
