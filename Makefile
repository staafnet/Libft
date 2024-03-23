NAME = libft.a
LOG_FILE = libft.log
CC = cc
CFLAGS = -Wall -Wextra -Werror
DATE_TIME := $(shell date +"%Y-%m-%d %T")

OBJS_DIR := objs/
BONUS_DIR := bonus/
TESTS_DIR := tests/

GREEN = \033[32m
BLUE = \033[34m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS := $(wildcard $(BONUS_DIR)*.c)
BONUS_OBJ := $(patsubst $(BONUS_DIR)%.c, $(OBJS_DIR)%.o, $(BONUS))
TESTS := $(wildcard $(TESTS_DIR)*.c)
TEST_OBJ := $(patsubst $(TESTS_DIR)%.c, $(OBJS_DIR)%.o, $(TESTS))

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^ && echo "$(GREEN)[✔] Library created $(RESET)"; \
    echo "$(DATE_TIME) [✔] Library created" >> $(LOG_FILE); \

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR); \
    touch $(LOG_FILE); \
	$(CC) $(CFLAGS) -c $< -o $@ && \
	echo "$(BLUE)[✔] Compiled: $<$(RESET)"

bonus: $(BONUS_OBJ)
	@if [ ! -f $(NAME) ]; then \
        echo "$(YELLOW)[!] Before using 'make bonus', please run 'make' to generate the library$(RESET)"; \
        echo "$(DATE_TIME) [!] Before using 'make bonus', please run 'make' to generate the library" >> $(LOG_FILE); \
    else \
        if ar t $(NAME) | grep -q "bonus.o"; then \
            echo "$(YELLOW)[!] Bonus functions were already added to the library$(RESET)"; \
			echo "$(DATE_TIME) [!] Bonus functions were already added to the library" >> $(LOG_FILE); \
		else \
            ar rcs $(NAME) $^ && \
			echo "$(GREEN)[✔] Bonus functions added to the library $(RESET)"; \
			echo "$(DATE_TIME) [✔] Bonus functions added to the library" >> $(LOG_FILE); \
		fi \
    fi

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c | $(OBJS_DIR)
	@if [ -f $(NAME) ]; then \
		$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "$(BLUE)[✔] Compiled: $<$(RESET)"; \
	fi

tests: $(TEST_OBJ)
	@if [ ! -f $(NAME) ]; then \
        echo "$(YELLOW)[!] Before using 'make tests', please run 'make' to generate the library$(RESET)"; \
        echo "$(DATE_TIME) [!] Before using 'make tests', please run 'make' to generate the library" >> $(LOG_FILE); \
    else \
        if [ -f "run_tests" ]; then \
            echo "$(YELLOW)[!] Tests were already compiled$(RESET)"; \
			echo "$(DATE_TIME) [!] Tests were already compiled" >> $(LOG_FILE); \
		else \
			$(CC) $(CFLAGS) -o run_tests $(TEST_OBJ) $(NAME) && \
			echo "$(GREEN)[✔] Tests compiled. To run, use: ./run_tests$(RESET)"; \
			echo "$(DATE_TIME) [✔] Tests compiled" >> $(LOG_FILE); \
		fi \
    fi
	

$(OBJS_DIR)%.o: $(TESTS_DIR)%.c | $(OBJS_DIR)
	@if [ -f $(NAME) ]; then \
		$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "$(BLUE)[✔] Compiled: $<$(RESET)"; \
	fi

clean:
	@rm -rf $(OBJS_DIR)* && echo "$(RED)[✔] Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME) run_tests && echo "$(RED)[✔] Library removed\n[✔] Test program removed$(RESET)"

re: fclean all

.PHONY: all bonus tests clean fclean re