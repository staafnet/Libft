#include "../bonus/libft_bonus.h"

void ft_lstadd_back_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstadd_back:\n" COLOR_RESET);

	int success = 1;
	t_list *lst = NULL;

	// Tworzymy nowe elementy bezpośrednio w teście
	t_list elements[] = {
		{.content = "First element", .next = NULL},
		{.content = "Second element", .next = NULL},
		{.content = "Third element", .next = NULL}};

	// Dodajemy elementy na koniec listy przy użyciu pętli while
	int i = 0;
	while (i < 3)
	{
		ft_lstadd_back(&lst, &elements[i]);
		i++;
	}

	// Sprawdzamy, czy elementy zostały dodane poprawnie na końcu listy
	t_list *current = lst;
	i = 0;
	while (current && i < 3)
	{
		if (current != &elements[i])
		{
			printf(COLOR_RED "Test failed: Element %d not added correctly to the end of the list\n" COLOR_RESET, i + 1);
			success = 0;
			break;
		}
		current = current->next;
		i++;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
}
