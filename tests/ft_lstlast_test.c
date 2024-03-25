#include "../bonus/libft_bonus.h"

void ft_lstlast_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstlast:\n" COLOR_RESET);

	// Test 1: Lista pusta
	t_list *empty_list = NULL;
	t_list *last_empty = ft_lstlast(empty_list);
	if (last_empty == NULL)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Lista z jednym elementem
	t_list single_node;
	char *data1 = "Test data";
	single_node.content = data1;
	single_node.next = NULL;
	t_list *last_single = ft_lstlast(&single_node);
	if (last_single == &single_node)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Lista z trzema elementami
	t_list multi_node[3];
	char *data2 = "First element";
	char *data3 = "Second element";
	char *data4 = "Third element";
	multi_node[0].content = data2;
	multi_node[0].next = &multi_node[1];
	multi_node[1].content = data3;
	multi_node[1].next = &multi_node[2];
	multi_node[2].content = data4;
	multi_node[2].next = NULL;
	t_list *last_multi = ft_lstlast(&multi_node[0]);
	if (last_multi == &multi_node[2])
		printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 3 failed!\n" COLOR_RESET);
}

int main(void)
{
	ft_lstlast_test();
	return (0);
}
