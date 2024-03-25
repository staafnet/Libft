#include "../bonus/libft_bonus.h"

// Funkcja testująca - wyświetla zawartość elementu listy
void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

void ft_lstiter_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstiter:\n" COLOR_RESET);

	// Test 1: Lista pusta
	t_list *empty_list = NULL;
	ft_lstiter(empty_list, &print_content); // Oczekujemy na brak wyjścia
	printf(COLOR_GREEN "Test 1 passed!\n" COLOR_RESET);

	// Test 2: Lista z jednym elementem
	char *data = "Test data";
	t_list node;
	node.content = data;
	node.next = NULL;
	ft_lstiter(&node, &print_content); // Powinno wyświetlić "Test data"
	printf(COLOR_GREEN "Test 2 passed!\n" COLOR_RESET);

	// Test 3: Lista z trzema elementami
	char *data1 = "First element";
	t_list first;
	first.content = data1;
	t_list second;
	char *data2 = "Second element";
	second.content = data2;
	t_list third;
	char *data3 = "Third element";
	third.content = data3;

	first.next = &second;
	second.next = &third;
	third.next = NULL;

	ft_lstiter(&first, &print_content); // Powinno wyświetlić: "First element", "Second element", "Third element"
	printf(COLOR_GREEN "Test 3 passed!\n" COLOR_RESET);
}

int main(void)
{
	ft_lstiter_test();
	return (0);
}
