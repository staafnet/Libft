#include "../libft.h"

void ft_memmove_test(void)
{
	printf(COLOR_BLUE "Testing ft_memmove:\n" COLOR_RESET);

	// Test 1: Podstawowy test
	char src1[] = "Hello, World!";
	char dst1[20];
	ft_memmove(dst1, src1, strlen(src1) + 1);
	char dst1_std[20];
	memmove(dst1_std, src1, strlen(src1) + 1);
	if (memcmp(dst1, dst1_std, sizeof(dst1)) == 0)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Przypadki, w których obszary źródłowy i docelowy się nakładają
	char dst2[] = "Hello, World!";
	ft_memmove(dst2 + 7, dst2, strlen(dst2) + 1);
	char dst2_std[] = "Hello, Hello, World!";
	memmove(dst2_std + 7, dst2_std, strlen(dst2_std) + 1);
	if (memcmp(dst2, dst2_std, sizeof(dst2)) == 0)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Kiedy obszar źródłowy i docelowy nie się nakładają, a źródłowy znajduje się przed docelowym
	char src3[] = "Hello, World!";
	char dst3[20];
	ft_memmove(dst3, src3, 7);
	char dst3_std[20];
	memmove(dst3_std, src3, 7);
	if (memcmp(dst3, dst3_std, sizeof(dst3)) == 0)
		printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);

	// Test 4: Kiedy obszar źródłowy i docelowy nie się nakładają, a źródłowy znajduje się za docelowym
	char src4[] = "Hello, World!";
	char dst4[20] = "Hi, ";
	ft_memmove(dst4 + 4, src4, strlen(src4) + 1);
	char dst4_std[20] = "Hi, Hello, World!";
	memmove(dst4_std + 4, src4, strlen(src4) + 1);
	if (memcmp(dst4, dst4_std, sizeof(dst4)) == 0)
		printf(COLOR_GREEN "Test 4 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 4 failed!\n" COLOR_RESET);
}