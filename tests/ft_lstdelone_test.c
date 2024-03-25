#include "../bonus/libft_bonus.h"

void del(void *content)
{
	free(content);
}

void ft_lstdelone_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstdelone:\n" COLOR_RESET);

	// Test 1: Lista z jednym elementem
	char data[] = "Test data";
	t_list *node = malloc(sizeof(t_list));
	if (node)
	{
		node->content = data;
		node->next = NULL;
	}
	ft_lstdelone(node, &del);
	if (node == NULL)
		printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 1 failed!\n" COLOR_RESET);

	// Test 2: Lista pusta
	t_list *empty_node = NULL;
	ft_lstdelone(empty_node, &del);
	if (empty_node == NULL)
		printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);
	else
		printf(COLOR_RED "Test 2 failed!\n" COLOR_RESET);

	// Test 3: Lista z trzema elementami - usuwanie drugiego elementu
	char data1[] = "First element";
	t_list *first = malloc(sizeof(t_list));
	if (first)
	{
		first->content = data1;
		first->next = NULL;
	}
	char data2[] = "Second element";
	t_list *second = malloc(sizeof(t_list));
	if (second)
	{
		second->content = data2;
		second->next = NULL;
	}
	char data3[] = "Third element";
	t_list *third = malloc(sizeof(t_list));
	if (third)
	{
		third->content = data3;
		third->next = NULL;
	}

	// Połącz elementy w listę
	first->next = second;
	second->next = third;

	// Usuń drugi element
	ft_lstdelone(second, &del);

	// Sprawdź, czy drugi element został usunięty
	if (second == NULL)
		printf(COLOR_GREEN "Second element deleted successfully!\n" COLOR_RESET);
	else
	{
		printf(COLOR_RED "Failed to delete second element!\n" COLOR_RESET);
		return;
	}

	// Sprawdź, czy lista nadal zawiera tylko dwa elementy
	if (first->next == third && third->next == NULL)
		printf(COLOR_GREEN "List still contains two elements!\n" COLOR_RESET);
	else
		printf(COLOR_RED "List does not contain two elements!\n" COLOR_RESET);
}
