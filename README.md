libft/
├── Makefile
├── libft.h
├── libft.log
├── README.md
├── objs/
├── ft_*.c
├── bonus/
│   ├── ft_*_bonus.c
│   └── libft_bonus.h
└── tests/
    └── ft_*_test.c

LIBFT requirements:
	General:
		- Declaring global variables not allowed.
		- All files at the root level of repository.
		- Should use the "ar" command to create library.
	Makefile:
		- flags:
			-Wall, -Wextra, -Werror
		- compiler:
			cc
		- rules:
			$(NAME), all, clean, fclean, re, tests, bonus
	Bonus:
		- Bonuses must be in another file _bonus.{c/h}

Part 1 - Libc functions:
	- ft_isalpha
	- ft_isdigit
	- ft_isalnum
	- ft_isascii
	- ft_isprint
	- ft_strlen
	- ft_memset
	- ft_bzero
	- ft_memcpy
	- ft_memmove
	- ft_strlcpy
	- ft_strlcat
	- ft_toupper
	- ft_tolower
	- ft_strchr
	- ft_strrchr
	- ft_strncmp
	- ft_memchr
	- ft_memcmp
	- ft_strnstr
	- ft_atoi

	To implement the following two functions, you will use malloc():
	- ft_calloc
	- ft_strdup

Part 2 - Additional functions:
	- ft_substr
	- ft_strjoin
    - ft_strtrim
	- ft_split
    - ft_itoa
    - ft_strmapi
    - ft_putchar_fd
    - ft_putstr_fd
    - ft_putendl_fd
    - ft_putnbr_fd

Partie bonus - Fonctions pour la gestion des listes:
    ft_lstnew.c
    ft_lstadd_front.c
    ft_lstsize.c
    ft_lstlast.c
    ft_lstadd_back.c
    ft_lstdelone.c
    ft_lstclear.c
    ft_lstiter.c
    ft_lstmap.c

