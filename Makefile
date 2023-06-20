# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 15:15:21 by matde-je          #+#    #+#              #
#    Updated: 2023/06/20 19:03:55 by matde-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
LIBFTPRINTF = printf

all: $(NAME)
		gcc $(FLAG) server.c $(NAME) -o server
		gcc $(FLAG) client.c $(NAME) -o client

$(NAME): $(LIBFTPRINTF)
		make -C $(LIBFTPRINTF)
		cp printf/libftprintf.a .

clean:
		make clean -C $(LIBFTPRINTF)
		rm -rf server.o client.o
		rm -rf server client

fclean: clean
		make fclean -C $(LIBFTPRINTF)
		rm -rf $(NAME)
		rm -rf server client

re: fclean all

.PHONY: clean fclean re 
