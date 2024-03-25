#include "../libft.h"

void ft_putnbr_fd_test(void)
{
	printf(COLOR_BLUE "Testing ft_putnbr_fd:\n" COLOR_RESET);

	// Test 1: Wyświetlenie liczby całkowitej na standardowe wyjście (stdout)
	printf("Test 1: Writing number 123 to stdout\n");
	ft_putnbr_fd(123, STDOUT_FILENO);

	// Test 2: Wyświetlenie liczby całkowitej na standardowe wyjście (stdout)
	printf("Test 2: Writing number -456 to stdout\n");
	ft_putnbr_fd(-456, STDOUT_FILENO);

	// Test 3: Wyświetlenie liczby całkowitej na standardowe wyjście (stdout)
	printf("Test 3: Writing number 0 to stdout\n");
	ft_putnbr_fd(0, STDOUT_FILENO);

	// Test 4: Wyświetlenie liczby całkowitej na standardowe wyjście (stdout)
	printf("Test 4: Writing number -2147483648 to stdout\n");
	ft_putnbr_fd(-2147483648, STDOUT_FILENO);

	// Test 5: Zapis liczby całkowitej do pliku (np. "output.txt")
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		printf("Test 5: Writing number 789 to file 'output.txt'\n");
		ft_putnbr_fd(789, fd);
		close(fd);

		// Sprawdzenie zgodności tekstu w pliku
		char buffer[100];
		fd = open("output.txt", O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		close(fd);

		int success = 1;
		if (strcmp(buffer, "789") != 0)
		{
			printf(COLOR_RED "Test 5 failed: Text in file does not match expected.\n" COLOR_RESET);
			success = 0;
		}

		if (!success)
			remove("output.txt"); // Usunięcie pliku w przypadku niepowodzenia
	}
	else
	{
		printf(COLOR_RED"Test 5: Cannot open file for writing. Skipping.\n" COLOR_RESET);
	}

	// Dodaj więcej testów według potrzeb
}