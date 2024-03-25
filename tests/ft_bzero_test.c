#include "../libft.h"

void ft_bzero_test(void)
{
	printf(COLOR_BLUE "Testing ft_bzero:\n" COLOR_RESET);

	char test_str1[20] = "Hello, world!";
	char test_str2[20] = "Hello, world!";
	int i = 0;
	int success = 1;

	while (i++ <= 20)
	{
		ft_bzero(test_str1, i);
		bzero(test_str2, i);

		if (memcmp(test_str1, test_str2, sizeof(test_str1)) != 0)
		{
			printf(COLOR_RED "Test failed: ft_bzero did not zero the first %d bytes correctly\n" COLOR_RESET, i);
			success = 0;
		}
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}