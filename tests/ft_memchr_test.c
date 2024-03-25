#include "../libft.h"


void ft_memchr_test(void)
{
	printf(COLOR_BLUE "Testing ft_memchr:\n" COLOR_RESET);

	char *testcases[] = {
		"Hello, world!",
		"Test string",
		"",
		NULL};

	int test_char[] = {'l', 'T', '\0', 'x'};
	size_t test_lengths[] = {13, 11, 0, 5};

	int num_testcases = sizeof(testcases) / sizeof(testcases[0]);
	int success = 1;

	int i = 0;
	while (i < num_testcases)
	{
		char *str = testcases[i];
		int ch = test_char[i];
		size_t length = test_lengths[i];

		void *result_ft = ft_memchr(str, ch, length);
		void *result_std = memchr(str, ch, length);

		if (result_ft != result_std)
		{
			printf(COLOR_RED "Test failed: ft_memchr did not match the behavior of memchr for test case %d\n" COLOR_RESET, i + 1);
			success = 0;
		}

		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
