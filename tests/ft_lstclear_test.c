#include "../bonus/libft_bonus.h"

void del(void *content)
{
	free(content);
}

void ft_lstclear_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstclear:\n" COLOR_RESET);

	// Test 1: Lista pusta
	t_list *empty_list = NULL;
	ft_lstclear(&empty_list, &del);
	if (empty_list == NULL)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Lista z jednym elementem
	char data[] = "Test data";
	t_list *single_node_list = malloc(sizeof(t_list));
	single_node_list->content = data;
	single_node_list->next = NULL;
	ft_lstclear(&single_node_list, &del);
	if (single_node_list == NULL)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Lista z wieloma elementami
	t_list *multi_node_list[5];
	int i = 0;
	while (i < 5)
	{
		multi_node_list[i] = malloc(sizeof(t_list));
		multi_node_list[i]->content = data;
		if (i < 4)
			multi_node_list[i]->next = multi_node_list[i + 1];
		else
			multi_node_list[i]->next = NULL;
		i++;
	}
	ft_lstclear(&multi_node_list[0], &del);
	if (multi_node_list[0] == NULL)
		printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);
}
