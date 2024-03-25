#include "../bonus/libft_bonus.h"

int main(void)
{
	printf(COLOR_BLUE "Testing ft_lstnew:\n" COLOR_RESET);

	// Test 1: Tworzenie nowego elementu z danymi "Hello, world!"
	char *data = "Hello, world!";
	t_list *node = ft_lstnew(data);
	if (node != NULL && node->content == data && node->next == NULL)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Tworzenie nowego elementu z pustymi danymi
	t_list *empty_node = ft_lstnew(NULL);
	if (empty_node != NULL && empty_node->content == NULL && empty_node->next == NULL)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Próba tworzenia nowego elementu z błędnym wskaźnikiem
	t_list *invalid_node = ft_lstnew((void *)0xDEADBEEF);
	if (invalid_node == NULL)
		printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);

	return (0);
}
