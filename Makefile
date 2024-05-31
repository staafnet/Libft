# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgrochow <staafnet@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 15:22:41 by rgrochow          #+#    #+#              #
#    Updated: 2024/04/05 09:21:16 by rgrochow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define project variables from configuration file
PROJECT_NAME := $(shell sed -n 's/^PROJECT_NAME=//p' config.cfg)
CREATION_DATE := $(shell sed -n 's/^CREATION_DATE=//p' config.cfg)
AUTHOR := $(shell sed -n 's/^AUTHOR=//p' config.cfg)
EMAIL := $(shell sed -n 's/^EMAIL=//p' config.cfg)
VERSION := $(shell sed -n 's/^VERSION=//p' config.cfg)
NAME := $(shell sed -n 's/^NAME=//p' config.cfg)
LOG_FILE := $(shell sed -n 's/^LOG_FILE=//p' config.cfg)
CONFIG_FILE := $(shell sed -n 's/^CONFIG_FILE=//p' config.cfg)
CC := $(shell sed -n 's/^CC=//p' config.cfg)
CFLAGS := $(shell sed -n 's/^CFLAGS=//p' config.cfg)
DOCKER_ENV := $(shell sed -n 's/^DOCKER_ENV=//p' config.cfg)
OBJS_DIR := $(shell sed -n 's/^OBJS_DIR=//p' config.cfg)
BONUS_DIR := $(shell sed -n 's/^BONUS_DIR=//p' config.cfg)
TESTS_DIR := $(shell sed -n 's/^TESTS_DIR=//p' config.cfg)
DATE_TIME = $(shell date +"%Y-%m-%d %T")
VALGRIND := $(shell which valgrind)

# Define color variables
PURPLE := $(shell grep '^PURPLE' config.cfg | cut -d'=' -f2)
GREEN := $(shell grep '^GREEN' config.cfg | cut -d'=' -f2)
AQUA := $(shell grep '^AQUA' config.cfg | cut -d'=' -f2)
BLUE := $(shell grep '^BLUE' config.cfg | cut -d'=' -f2)
RED := $(shell grep '^RED' config.cfg | cut -d'=' -f2)
YELLOW := $(shell grep '^YELLOW' config.cfg | cut -d'=' -f2)
RESET := $(shell grep '^RESET' config.cfg | cut -d'=' -f2)

# Define source and object files
SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS := $(wildcard $(BONUS_DIR)*.c)
BONUS_OBJ := $(patsubst $(BONUS_DIR)%.c, $(OBJS_DIR)%.o, $(BONUS))
TESTS := $(wildcard $(TESTS_DIR)*.c)
TEST_OBJ := $(patsubst $(TESTS_DIR)%.c, $(OBJS_DIR)%.o, $(TESTS))

# Define Docker installation command based on the operating system
ifeq ($(shell uname -s),Linux)
    DOCKER_INSTALL_CMD = sudo apt-get update && sudo apt-get install -y docker.io; \
	sudo systemctl start docker && sudo systemctl enable docker
endif
ifeq ($(shell uname -s),Darwin)
    DOCKER_INSTALL_CMD = brew install --cask docker
endif
ifeq ($(shell uname -s),Windows_NT)
    DOCKER_INSTALL_CMD = choco install docker-desktop
endif

# Default target
all: $(NAME)
	@if [ ! -f /.dockerenv ] && [ "$(DOCKER_ENV)" = "true" ]; then \
		sed -i 's/^DOCKER_ENV=.*$$/DOCKER_ENV=false/' config.cfg; \
		read -p "Use a Docker container to test Libft? (y/n): " answer; \
        if [ "$$answer" = "y" ] || [ "$$answer" = "Y" ]; then \
            make docker; \
		else \
			echo "\n$(YELLOW)             ▄█        ▄█  ▀█████████▄     ▄████████     ███"; \
			echo "            ███       ███    ███    ███   ███    ███ ▀█████████▄"; \
			echo "            ███       ███▌   ███    ███   ███    █▀     ▀███▀▀██"; \
			echo "            ███       ███▌  ▄███▄▄▄██▀   ▄███▄▄▄         ███   ▀"; \
			echo "            ███       ███▌ ▀▀███▀▀▀██▄  ▀▀███▀▀▀         ███    "; \
			echo "            ███       ███    ███    ██▄   ███            ███    "; \
			echo "            ███       ███    ███    ███   ███            ███    "; \
			echo "            ███▌    ▄ ███    ███    ███   ███            ███    "; \
			echo "            █████▄▄██ █▀   ▄█████████▀    ███           ▄████▀  "; \
			echo "            ▀$(RESET)"; \
			echo "\n$(GREEN)# **************************************************************************** #"; \
			echo "#                                                                              #"; \
			echo "#                                                         :::    ::::::::      #"; \
			echo -n "#    $(PROJECT_NAME)" && echo -n "\033[56G" && echo " :+:    :+:    :+:      #"; \
			echo "#                                                     +:+ +:+       +:+        #"; \
			echo -n "#    By: $(AUTHOR) <$(EMAIL)>" && echo -n "\033[52G" && echo " +#+  +:+      +#+          #"; \
			echo "#                                                 +#+#+#+#+#+   +#+            #"; \
			echo -n "#    Created: $(CREATION_DATE)" && echo -n "\033[55G" && echo " #+#    #+#              #"; \
			echo -n "#    Version: $(VERSION) " && echo -n "\033[54G" && echo " ###   ########.fr        #"; \
			echo "#                                                                              #"; \
			echo "# **************************************************************************** #"; \
			echo "#                                                                              #"; \
			echo "# ---------------------------- Library created ! ----------------------------- #"; \
			echo "#                                                                              #"; \
			echo "# ---------------------- Mandatory functions compiled ! ---------------------- #"; \
			echo "#                                                                              #$(RESET)"; \
			echo "$(AQUA)# ***  Welcome to the $(PURPLE)'LIBFT'$(RESET)$(AQUA) project, for more questions type $(PURPLE)'make help'$(RESET)$(AQUA) *** #$(RESET)\n"; \
        fi \
    fi

# Rule to create the library
$(NAME): $(OBJS)
	@ar rcs $@ $^ && echo "$(DATE_TIME) [✔] Library created" >> $(LOG_FILE); \

# Rule to compile object files
$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR); \
    touch $(LOG_FILE); \
	$(CC) $(CFLAGS) -c $< -o $@; \
	echo "$(BLUE)[✔] Compiled: $<$(RESET)"

# Rule to start Docker container
docker:
	@if [ ! -f /.dockerenv ]; then \
		if [ ! -f $(NAME) ]; then \
			MSG="Before using 'make docker', please run 'make' to generate the library"; \
			echo "$(YELLOW)[!] $$MSG$(RESET)"; \
			echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
		else \
			echo "$(DATE_TIME) [✔] Starting Docker" >> $(LOG_FILE); \
			$(DOCKER_INSTALL_CMD); \
			sudo docker build -t libft-env -q .; \
			sudo docker run -it libft-env; \
		fi \
	else \
		MSG="You are already in a Docker container"; \
		echo "$(YELLOW)[!] $$MSG$(RESET)"; \
		echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
	fi

# Rule to add bonus functions to the library
bonus: $(BONUS_OBJ)
	@if [ ! -f $(NAME) ]; then \
		MSG="Before using 'make bonus', please run 'make' to generate the library"; \
			echo "$(YELLOW)[!] $$MSG$(RESET)"; \
			echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
    else \
        if ar t $(NAME) | grep -q "ft_lstadd_back.o"; then \
			MSG="Bonus functions were already added to the library"; \
            echo "$(YELLOW)[!] $$MSG$(RESET)"; \
			echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
		else \
            ar rcs $(NAME) $^ && \
			MSG="Bonus functions added to the library"; \
			echo "$(GREEN)[✔] $$MSG$(RESET)"; \
			echo "$(DATE_TIME) [✔] $$MSG" >> $(LOG_FILE); \
		fi \
    fi

# Rule to compile bonus object files
$(OBJS_DIR)%.o: $(BONUS_DIR)%.c | $(OBJS_DIR)
	@if [ -f $(NAME) ]; then \
		$(CC) $(CFLAGS) -c $< -o $@; \
		echo "$(BLUE)[✔] Compiled: $<$(RESET)"; \
	fi

# Rule to compile tests and run them with Valgrind
tests: $(TEST_OBJ)
	@if [ ! -f $(NAME) ]; then \
		MSG="Before using 'make tests', please run 'make' to generate the library"; \
        echo "$(YELLOW)[!] $$MSG$(RESET)"; \
        echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
    else \
        if [ ! -f "run_tests" ]; then \
			$(CC) $(CFLAGS) -o run_tests $(TEST_OBJ) $(NAME); \
			MSG="Tests compiled"; \
			echo "$(GREEN)[✔] $$MSG$(RESET)"; \
			echo "$(DATE_TIME) [✔] $$MSG" >> $(LOG_FILE); \
		fi; \
		if [ -x "$(VALGRIND)" ]; then \
			MSG="Valgrind is installed. Running tests with Valgrind..."; \
    		echo "$(GREEN)[✔] $$MSG$(RESET)"; \
    		echo "$(DATE_TIME) [✔] $$MSG" >> $(LOG_FILE); \
    		$(VALGRIND) $(VALGRIND_OPTS) ./run_tests; \
		else \
			MSG="Valgrind is not installed. Skipping Valgrind tests..."; \
    		echo "$(YELLOW)[!] $$MSG$(RESET)"; \
    		echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
    		./run_tests; \
		fi \
	fi

# Rule to compile tests object files
$(OBJS_DIR)%.o: $(TESTS_DIR)%.c | $(OBJS_DIR)
	@if [ -f $(NAME) ]; then \
		$(CC) $(CFLAGS) -c $< -o $@; \
		echo "$(BLUE)[✔] Compiled: $<$(RESET)"; \
	fi

# Rule to display list of compiled files
list:
	@if [ ! -f $(NAME) ]; then \
		MSG="Przed użyciem 'make list', proszę uruchomić 'make', aby wygenerować bibliotekę"; \
        echo "$(YELLOW)[!] $$MSG$(RESET)"; \
        echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
    else \
		echo -n "$(BLUE)"; \
		count=0; \
		i=1; \
		find . -maxdepth 1 -name '*.c' | while read -r file; do \
			if [ $$count -eq 2 ]; then \
				echo ""; \
				count=0; \
			fi; \
			length=$$(echo $$file | wc -c); \
			spaces=$$((28 - length)); \
			if [ $$i -ge 10 ]; then \
				spaces=$$((spaces - 1)); \
			fi; \
			printf "$$i. $$file%$$spaces""s "; \
			count=$$((count + 1)); \
			i=$$((i + 1)); \
		done; \
        echo ""; \
		echo ""; \
		find bonus/ -name '*.c' -o -name '*.c' | while read -r file; do \
			if [ $$count -eq 2 ]; then \
				echo ""; \
				count=0; \
			fi; \
			length=$$(echo $$file | wc -c); \
			spaces=$$((28 - length)); \
			if [ $$i -ge 10 ]; then \
				spaces=$$((spaces - 1)); \
			fi; \
			printf "$$i. $$file%$$spaces""s "; \
			count=$$((count + 1)); \
			i=$$((i + 1)); \
		done; \
		echo "$(RESET)"; \
	fi \



# Rule to display help message
help:
	@if [ ! -f $(NAME) ]; then \
		MSG="Before using 'make list', please run 'make' to generate the library"; \
        echo "$(YELLOW)[!] $$MSG$(RESET)"; \
        echo "$(DATE_TIME) [!] $$MSG" >> $(LOG_FILE); \
    else \
		echo "$(YELLOW)Available commands:$(RESET)"; \
		echo "  - $(BLUE)all$(RESET):        $(AQUA)Compile the library$(RESET)."; \
		echo "  - $(BLUE)docker$(RESET):     $(AQUA)Start Docker container$(RESET)."; \
		echo "  - $(BLUE)bonus$(RESET):      $(AQUA)Add bonus functions to the library$(RESET)."; \
		echo "  - $(BLUE)tests$(RESET):      $(AQUA)Compile and run tests with Valgrind check$(RESET)."; \
		echo "  - $(BLUE)list$(RESET):       $(AQUA)Show list of compiled files$(RESET)."; \
		echo "  - $(BLUE)clean$(RESET):      $(AQUA)Remove object files$(RESET)."; \
		echo "  - $(BLUE)fclean$(RESET):     $(AQUA)Remove object files, library, and test program$(RESET)."; \
		echo "  - $(BLUE)re$(RESET):         $(AQUA)Perform 'fclean' followed by 'all'$(RESET)."; \
		echo "  - $(BLUE)help$(RESET):       $(AQUA)Display this help message$(RESET)."; \
	fi
# Rule to clean object files
clean:
	@rm -rf $(OBJS_DIR)* && echo "$(RED)[✔] Objects removed$(RESET)"

# Rule to clean object files, library, and test program
fclean: clean
	@sed -i 's/^DOCKER_ENV=.*$$/DOCKER_ENV=true/' config.cfg; \
	rm -f $(NAME) run_tests && echo "$(RED)[✔] Library removed\n[✔] Test program removed$(RESET)"

# Rule to perform 'fclean' followed by 'all'
re: fclean all

.PHONY: all bonus tests clean fclean re help docker list
