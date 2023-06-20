# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 15:15:21 by matde-je          #+#    #+#              #
#    Updated: 2023/06/20 16:39:55 by matde-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= 	server
CLIENT_NAME		=	client
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror
OBJ_SERV		= 	server.o libft.o
OBJ_CLIENT		= 	client.o libft.o

all: 		$(SERVER_NAME) $(CLIENT_NAME)
			$(SERVER_NAME):	$(OBJ_SERV)
			@$(CC) $(CFLAGS) $(OBJ_SERV) -o $(SERVER_NAME)
			$(CLIENT_NAME):	$(OBJ_CLIENT)
			@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT_NAME)

clean:
			rm -f $(OBJ_SERV) $(OBJ_CLIENT)

fclean: clean
			rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: 	all re clean fclean m 
