# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 21:06:36 by rgrochow          #+#    #+#              #
#    Updated: 2024/03/11 21:20:25 by rgrochow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes/
OBJS_DIR = objs/
SRCS_DIR = srcs/
BONUS_DIR = bonus/
TESTS_DIR = tests/

GREEN = \033[32m
BLUE = \033[34m
RED = \033[31m
RESET = \033[0m

SRCS := $(wildcard $(SRCS_DIR)*.c)
BONUS_SRCS := $(wildcard $(BONUS_DIR)*.c)
TESTS := $(wildcard $(TESTS_DIR)*.c)

SRCS_OBJ := $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS_OBJ := $(patsubst $(BONUS_DIR)%.c, $(OBJS_DIR)%.o, $(BONUS_SRCS))
TEST_OBJ := $(patsubst $(TESTS_DIR)%.c, $(OBJS_DIR)%.o, $(TESTS))

all: $(NAME) tests bonus

$(NAME): $(SRCS_OBJ)
	@ar rcs $@ $^ && echo "$(GREEN)[✔] Library created $(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@ && \
	echo "$(BLUE)[✔] Compiled: $<$(RESET)"

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@ && \
	echo "$(BLUE)[✔] Compiled: $<$(RESET)"

$(OBJS_DIR)%.o: $(TESTS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@ && \
	echo "$(BLUE)[✔] Compiled: $<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $@ && echo "$(GREEN)[✔] Object directory created$(RESET)"

tests: $(TEST_OBJ) $(NAME)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -o run_tests $(TEST_OBJ) $(NAME)
	@echo "$(GREEN)Tests compiled. To run, use: ./run_tests$(RESET)"

bonus: $(BONUS_OBJ)
	@ar rcs $(NAME) $^ && echo "$(GREEN)[✔] Bonus functions added to the library $(RESET)"

clean:
	@rm -rf $(OBJS_DIR) && echo "$(RED)[✔] Objects removed$(RESET)"

fclean: clean
	@rm -f $(NAME) run_tests && echo "$(RED)[✔] Library and test program removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re tests bonus
