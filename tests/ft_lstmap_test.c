#include "../bonus/libft_bonus.h"

// Testowa funkcja - dodaje 1 do wartości int
void *add_one(void *content)
{
	int *num = (int *)content;
	int *new_num = (int *)malloc(sizeof(int));
	if (new_num)
		*new_num = *num + 1;
	return new_num;
}

// Testowa funkcja - zwalnia pamięć dla wartości int
void del(void *content)
{
	free(content);
}

// Test funkcji ft_lstmap
void ft_lstmap_test(void)
{
	printf(COLOR_BLUE "Testing ft_lstmap:\n" COLOR_RESET);

	// Tworzenie testowej listy
	t_list *lst = NULL;
	int i = 0;
	while (i < 5)
	{
		int *num = (int *)malloc(sizeof(int));
		*num = i;
		t_list *new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node)
		{
			new_node->content = num;
			new_node->next = NULL;
			if (!lst)
				lst = new_node;
			else
			{
				t_list *temp = lst;
				while (temp->next)
					temp = temp->next;
				temp->next = new_node;
			}
		}
		i++;
	}

	// Wywołanie ft_lstmap z funkcją add_one
	t_list *mapped_lst = NULL;
	t_list *original_lst = lst;
	while (original_lst)
	{
		int *mapped_content = add_one(original_lst->content);
		t_list *new_node = (t_list *)malloc(sizeof(t_list));
		if (mapped_content && new_node)
		{
			new_node->content = mapped_content;
			new_node->next = NULL;
			if (!mapped_lst)
				mapped_lst = new_node;
			else
			{
				t_list *temp = mapped_lst;
				while (temp->next)
					temp = temp->next;
				temp->next = new_node;
			}
		}
		original_lst = original_lst->next;
	}

	// Sprawdzenie wyników
	while (lst && mapped_lst)
	{
		int *original_num = (int *)(lst->content);
		int *mapped_num = (int *)(mapped_lst->content);
		printf("Original: %d, Mapped: %d\n", *original_num, *mapped_num);
		lst = lst->next;
		mapped_lst = mapped_lst->next;
	}

	// Zwolnienie pamięci
	while (lst)
	{
		t_list *temp = lst->next;
		free(lst->content);
		free(lst);
		lst = temp;
	}
	while (mapped_lst)
	{
		t_list *temp = mapped_lst->next;
		free(mapped_lst->content);
		free(mapped_lst);
		mapped_lst = temp;
	}
}

int main(void)
{
	ft_lstmap_test();
	return (0);
}
