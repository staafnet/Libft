#include "../libft.h"

void ft_putchar_fd_test(void)
{
	printf(COLOR_BLUE "Testing ft_putchar_fd:\n" COLOR_RESET);

	// Test 1: Zapis pojedynczego znaku do standardowego wyjścia (stdout)
	printf("Test 1: Writing character 'A' to stdout\n");
	ft_putchar_fd('A', STDOUT_FILENO);

	// Test 2: Zapis wielu znaków do standardowego wyjścia (stdout)
	printf("Test 2: Writing characters 'B', 'C', 'D' to stdout\n");
	ft_putchar_fd('B', STDOUT_FILENO);
	ft_putchar_fd('C', STDOUT_FILENO);
	ft_putchar_fd('D', STDOUT_FILENO);

	// Test 3: Zapis znaków do pliku (np. "output.txt")
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		printf("Test 3: Writing character 'E' to file 'output.txt'\n");
		ft_putchar_fd('E', fd);
		close(fd);

		// Sprawdzenie zgodności tekstu w pliku
		char buffer[100];
		fd = open("output.txt", O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		close(fd);

		int success = 1;
		if (strcmp(buffer, "E") != 0)
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

	// Test 4: Zapis wielu znaków do pliku (np. "output.txt")
	fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd != -1)
	{
		printf("Test 4: Writing characters 'F', 'G', 'H' to file 'output.txt'\n");
		ft_putchar_fd('F', fd);
		ft_putchar_fd('G', fd);
		ft_putchar_fd('H', fd);
		close(fd);

		// Sprawdzenie zgodności tekstu w pliku
		char buffer[100];
		fd = open("output.txt", O_RDONLY);
		read(fd, buffer, sizeof(buffer));
		close(fd);

		int success = 1;
		if (strcmp(buffer, "EFGH") != 0)
		{
			printf(COLOR_RED "Test 4 failed: Text in file does not match expected.\n" COLOR_RESET);
			success = 0;
		}

		if (!success)
			remove("output.txt"); // Usunięcie pliku w przypadku niepowodzenia
	}
	else
	{
		printf(COLOR_RED "Test 4: Cannot open file for writing. Skipping.\n" COLOR_RESET);
	}

	// Dodaj więcej testów według potrzeb
}

int main(void)
{
	ft_putchar_fd_test();
	return (0);
}
