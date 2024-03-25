#include "../libft.h"

void ft_memcpy_test(void)
{
	printf(COLOR_BLUE "Testing ft_memcpy:\n" COLOR_RESET);
	char *testcases[][3] = {
		{"coucou", "A", "A"},
		{"coucou", "A", "coucou"},
		{"", "A", "A"},
		{"", "", ""},
		{NULL, "A", "A"},
		{"coucou", NULL, "coucou"},
		{NULL, NULL, ""},
		{"123", "456", "456"},
		{"\0", "abc", "abc"},
	};
	int idx = 0;
	int success = 1;
	int num_testcases = (int)(sizeof(testcases) / sizeof(testcases[0]));
	while (idx < num_testcases)
	{
		char dest_ft[100];
		char dest_std[100];
		char *src = testcases[idx][0];
		char *expected = testcases[idx][2];
		size_t n = strlen(testcases[idx][1]);
		ft_memcpy(dest_ft, src, n);
		memcpy(dest_std, src, n);
		if (memcmp(dest_ft, dest_std, sizeof(dest_ft)) != 0 || strcmp(dest_ft, expected) != 0)
		{
			printf(COLOR_RED "Test failed: ft_memcpy did not match the behavior of memcpy for test case %d\n" COLOR_RESET, idx + 1);
			success = 0;
		}
		idx++;
	}
	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
