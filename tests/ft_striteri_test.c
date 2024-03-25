#include "../libft.h"


void upper_char(unsigned int i, char *c)
{
	while (i > 0)
	{
		i--;
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32; // Zamień małą literę na dużą
	}
}

void ft_striteri_test(void)
{
	int success = 1;

	// Test 1: Łańcuch znaków pusty
	char empty_str_ft[] = "";
	ft_striteri(empty_str_ft, &upper_char);
	printf("After ft_striteri with empty string: %s\n", empty_str_ft);

	// Test 2: Zmiana małych liter na duże w istniejącym łańcuchu
	char s[] = "hello";
	ft_striteri(s, &upper_char);
	printf("After ft_striteri: %s\n", s);

	// Test 3: Iteracja po łańcuchu z jednym znakiem
	char single_char[] = "a";
	ft_striteri(single_char, &upper_char);
	printf("After ft_striteri with single character: %s\n", single_char);

	// Test 4: Iteracja po łańcuchu z wieloma znakami
	char multiple_chars[] = "abcXYZ";
	ft_striteri(multiple_chars, &upper_char);
	printf("After ft_striteri with multiple characters: %s\n", multiple_chars);

	// Test 5: Iteracja po łańcuchu zawierającym znaki specjalne
	char special_chars[] = "abc!@#";
	ft_striteri(special_chars, &upper_char);
	printf("After ft_striteri with special characters: %s\n", special_chars);

	// Test 6: Iteracja po łańcuchu, który nie wymaga modyfikacji
	char no_changes[] = "ABCXYZ";
	ft_striteri(no_changes, &upper_char);
	printf("After ft_striteri with no changes required: %s\n", no_changes);

	// Test 7: Iteracja po łańcuchu z dużą liczbą znaków
	char large_str[1000];
	for (int i = 0; i < 1000; ++i)
		large_str[i] = 'a'; // Wypełnij łańcuch małymi literami
	large_str[999] = '\0';	// Dodaj znak null-terminatora
	ft_striteri(large_str, &upper_char);
	printf("After ft_striteri with large string: %s\n", large_str);

	if (!success)
		printf("Some tests failed!\n");
	else
		printf("All tests passed successfully!\n");
}