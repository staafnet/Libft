FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
	build-essential \
	valgrind \
	python3 \
	python3-pip \
	&& rm -rf /var/lib/apt/lists/*

RUN pip3 install norminette

COPY . /root/

WORKDIR /root

CMD echo "\n\e[1;33m             ▄█        ▄█  ▀█████████▄     ▄████████     ███"; \
	echo "            ███       ███    ███    ███   ███    ███ ▀█████████▄"; \
	echo "            ███       ███▌   ███    ███   ███    █▀     ▀███▀▀██"; \
	echo "            ███       ███▌  ▄███▄▄▄██▀   ▄███▄▄▄         ███   ▀"; \
	echo "            ███       ███▌ ▀▀███▀▀▀██▄  ▀▀███▀▀▀         ███    "; \
	echo "            ███       ███    ███    ██▄   ███            ███    "; \
	echo "            ███▌    ▄ ███    ███    ███   ███            ███    "; \
	echo "            █████▄▄██ █▀   ▄█████████▀    ███           ▄████▀  "; \
	echo "            ▀\e[0m"; \
	echo "\n\e[1;32m# **************************************************************************** #" && \
	echo "#                                                                              #" && \
	echo "#                                                         :::    ::::::::      #" && \
	echo "#    LIBFT                                              :+:    :+:    :+:      #" && \
	echo "#                                                     +:+ +:+       +:+        #" && \
	echo "#    By: rgrochow <staafnet@gmail.com>              +#+  +:+      +#+          #" && \
	echo "#                                                 +#+#+#+#+#+   +#+            #" && \
	echo "#    Created: 2024/03/25 18:52:46 by rgrochow          #+#    #+#              #" && \
	echo "#                                                     ###   ########.fr        #" && \
	echo "#                                                                              #" && \
	echo "# **************************************************************************** #" && \
	echo "#                                                                              #" && \
	echo "# ---------------------------- Library created ! ----------------------------- #" && \
	echo "#                                                                              #" && \
	echo "# ---------------------- Mandatory functions compiled ! ---------------------- #" && \
	echo "#                                                                              #\e[0m" && \
	echo "\e[1;36m# ***  Welcome to the \e[1;35m'LIBFT'\e[0m\e[1;36m project, for more questions type \e[1;35m'make help'\e[0m\e[1;36m *** #\e[0m\n" && \
	bash