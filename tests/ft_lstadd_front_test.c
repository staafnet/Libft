#include "../bonus/libft_bonus.h"

void ft_lstadd_front_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstadd_front:\n" COLOR_RESET);

	int success = 1;
	t_list *lst = NULL;

	// Tworzymy nowe elementy bezpośrednio w teście
	t_list elements[] = {
		{.content = "First element", .next = NULL},
		{.content = "Second element", .next = NULL},
		{.content = "Third element", .next = NULL}};

	// Dodajemy elementy na początek listy przy użyciu pętli while
	int i = 0;
	while (i < 3)
	{
		ft_lstadd_front(&lst, &elements[i]);
		i++;
	}

	// Sprawdzamy, czy elementy zostały dodane poprawnie na początku listy
	t_list *current = lst;
	i = 2; // Sprawdzamy od końca listy
	while (current && i >= 0)
	{
		if (current != &elements[i])
		{
			printf(COLOR_RED "Test failed: Element %d not added correctly to the front of the list\n" COLOR_RESET, 3 - i);
			success = 0;
			break;
		}
		current = current->next;
		i--;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
