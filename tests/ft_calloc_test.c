#include "../libft.h"

void ft_calloc_test(void)
{
	printf(COLOR_BLUE "Testing ft_calloc:\n" COLOR_RESET);

	int success = 1;
	size_t len = 0;

	while (len <= 20)
	{
		
		void *ptr_ft = ft_calloc(1, len);
		void *ptr_std = calloc(1, len);

		
		if (!ptr_ft || !ptr_std)
		{
			printf(COLOR_RED "Test failed: Memory allocation failed\n" COLOR_RESET);
			success = 0;
			break;
		}

		
		if (memcmp(ptr_ft, ptr_std, len) != 0)
		{
			printf(COLOR_RED "Test failed: ft_calloc result differs from calloc result for length %zu\n" COLOR_RESET, len);
			success = 0;
			break;
		}
		free(ptr_ft);
		free(ptr_std);

		len++;
	}
	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
