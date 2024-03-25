#include "../bonus/libft_bonus.h"

void ft_lstsize_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstsize:\n" COLOR_RESET);

	// Test 1: Lista pusta
	t_list *empty_list = NULL;
	int size_empty = ft_lstsize(empty_list);
	if (size_empty == 0)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Lista z jednym elementem
	char *data = "Test data";
	t_list *single_node_list = malloc(sizeof(t_list));
	if (single_node_list)
	{
		single_node_list->content = data;
		single_node_list->next = NULL;
	}
	int size_single = ft_lstsize(single_node_list);
	if (size_single == 1)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Lista z wieloma elementami
	t_list *multi_node_list = malloc(sizeof(t_list));
	if (multi_node_list)
	{
		multi_node_list->content = data;
		multi_node_list->next = malloc(sizeof(t_list));
		if (multi_node_list->next)
		{
			multi_node_list->next->content = data;
			multi_node_list->next->next = malloc(sizeof(t_list));
			if (multi_node_list->next->next)
			{
				multi_node_list->next->next->content = data;
				multi_node_list->next->next->next = NULL;
			}
		}
	}
	int size_multi = ft_lstsize(multi_node_list);
	if (size_multi == 3)
		printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);

	// Zwolnienie zaalokowanej pamięci
	free(single_node_list);
	free(multi_node_list->next);
	free(multi_node_list->next->next);
	free(multi_node_list);
}