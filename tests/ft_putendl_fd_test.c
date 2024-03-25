#include "../libft.h"

void ft_putendl_fd_test(void)
{
	printf(COLOR_BLUE "Testing ft_putendl_fd:\n" COLOR_RESET);

	int success = 1;

	// Test 1: Sprawdź, czy jest poprawnie dodawany znak nowej linii
	int fd1 = open("putendl_fd_test1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("Hello", fd1);
	close(fd1);

	char buffer1[100];
	int fd_read1 = open("putendl_fd_test1.txt", O_RDONLY);
	read(fd_read1, buffer1, 6); // Czytaj 6 znaków (długość "Hello")
	buffer1[5] = '\0';			// Ustaw znak końca łańcucha
	close(fd_read1);

	if (strcmp(buffer1, "Hello\n") != 0)
	{
		printf(COLOR_RED "Test 1 failed: Incorrect newline character added.\n" COLOR_RESET);
		success = 0;
	}

	// Test 2: Sprawdź, czy funkcja poprawnie obsługuje pusty łańcuch
	int fd2 = open("putendl_fd_test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("", fd2);
	close(fd2);

	char buffer2[100];
	int fd_read2 = open("putendl_fd_test2.txt", O_RDONLY);
	read(fd_read2, buffer2, 1); // Czytaj 1 znak (powinien być znak nowej linii)
	buffer2[1] = '\0';			// Ustaw znak końca łańcucha
	close(fd_read2);

	if (strcmp(buffer2, "\n") != 0)
	{
		printf(COLOR_RED "Test 2 failed: Empty string not handled correctly.\n" COLOR_RESET);
		success = 0;
	}

	// Test 3: Sprawdź, czy funkcja poprawnie obsługuje null jako argument
	int fd3 = open("putendl_fd_test3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd(NULL, fd3);
	close(fd3);

	char buffer3[100];
	int fd_read3 = open("putendl_fd_test3.txt", O_RDONLY);
	read(fd_read3, buffer3, 1); // Czytaj 1 znak (powinien być znak nowej linii)
	buffer3[1] = '\0';			// Ustaw znak końca łańcucha
	close(fd_read3);

	if (strcmp(buffer3, "\n") != 0)
	{
		printf(COLOR_RED "Test 3 failed: NULL argument not handled correctly.\n" COLOR_RESET);
		success = 0;
	}

	if (success)
		printf(COLOR_GREEN "All tests passed successfully!\n" COLOR_RESET);
	remove("putendl_fd_test1.txt");
	remove("putendl_fd_test2.txt");
	remove("putendl_fd_test3.txt");
}
