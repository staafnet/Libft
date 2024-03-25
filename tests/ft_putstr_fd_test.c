#include "../libft.h"

void ft_putstr_fd_test(void)
{
	printf(COLOR_BLUE "Testing ft_putstr_fd:\n" COLOR_RESET);

	// Test 1: Wyświetlenie napisu na standardowe wyjście (stdout)
	printf("Test 1: Writing string 'Hello, World!' to stdout\n");
	ft_putstr_fd("Hello, World!", STDOUT_FILENO);

	// Test 2: Wyświetlenie napisu na standardowe wyjście (stdout)
	printf("Test 2: Writing string '' to stdout\n");
	ft_putstr_fd("", STDOUT_FILENO);

	// Test 3: Zapis napisu do pliku (np. "output.txt")
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		printf("Test 3: Writing string 'Testing ft_putstr_fd' to file 'output.txt'\n");
		ft_putstr_fd("Testing ft_putstr_fd", fd);
		close(fd);

		// Sprawdzenie zgodności tekstu w pliku
		char buffer[100];
		fd = open("output.txt", O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		close(fd);

		int success = 1;
		if (strcmp(buffer, "Testing ft_putstr_fd") != 0)
		{
			printf(COLOR_RED "Test 3 failed: Text in file does not match expected.\n" COLOR_RESET);
			success = 0;
		}

		if (!success)
			remove("output.txt"); // Usunięcie pliku w przypadku niepowodzenia
	}
	else
	{
		printf(COLOR_RED "Test 3: Cannot open file for writing. Skipping.\n" COLOR_RESET);
	}

	// Dodaj więcej testów według potrzeb
}