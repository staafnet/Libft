#include "libft.h"

static size_t count_words(const char *s, char c)
{
	size_t words = 0;
	int in_word = 0; // Flaga wskazująca, czy aktualnie jesteśmy w słowie
	while (*s)
	{
		if (*s == c)
		{
			in_word = 0;
		}
		else if (!in_word)
		{
			in_word = 1;
			words++;
		}
		s++;
	}
	return words;
}

static char *ft_strndup(const char *src, size_t n)
{
	char *dst = (char *)malloc(sizeof(char) * (n + 1));
	if (!dst)
		return NULL;
	size_t i;
	for (i = 0; i < n; i++)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0'; // Dodanie znaku null-terminatora
	return dst;
}

char **ft_split(char const *s, char c)
{
	if (!s)
		return NULL;

	size_t words = count_words(s, c);
	char **result = (char **)malloc(sizeof(char *) * (words + 1)); // Tablica na słowa plus NULL na końcu
	if (!result)
		return NULL;
	result[words] = NULL; // Ustawienie ostatniego elementu na NULL, zgodnie z wymogiem

	size_t word_index = 0;
	int in_word = 0;	   // Flaga wskazująca, czy aktualnie jesteśmy w słowie
	const char *start = s; // Wskaźnik na początek bieżącego słowa
	while (*s)
	{
		if (*s == c)
		{
			if (in_word)
			{
				// Jeśli byliśmy w słowie, to kopiujemy je do tablicy result
				result[word_index++] = ft_strndup(start, s - start);
				if (!result[word_index - 1])
				{
					// W przypadku błędu w alokacji pamięci zwalniamy dotychczasowe zaalokowane słowa i zwracamy NULL
					for (size_t i = 0; i < word_index; i++)
					{
						free(result[i]);
					}
					free(result);
					return NULL;
				}
				in_word = 0;
			}
		}
		else if (!in_word)
		{
			in_word = 1;
			start = s;
		}
		s++;
	}

	// Sprawdzamy, czy ostatnie słowo nie zostało przegapione (jeśli string kończy się znakiem inny niż 'c')
	if (in_word)
	{
		result[word_index++] = ft_strndup(start, s - start);
		if (!result[word_index - 1])
		{
			// W przypadku błędu w alokacji pamięci zwalniamy dotychczasowe zaalokowane słowa i zwracamy NULL
			for (size_t i = 0; i < word_index; i++)
			{
				free(result[i]);
			}
			free(result);
			return NULL;
		}
	}

	return result;
}
