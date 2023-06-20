# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 19:05:43 by matde-je          #+#    #+#              #
#    Updated: 2023/06/20 19:25:41 by matde-je         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	= 	ft_printf.c	\
			ftargfunc.c	\
			ft_putnbr.c	\
			ftchar.c	\
			ftint.c		\
			ft_strlen.c	\
			atoi.c

NAME 	=	libftprintf.a
OBJECTS	=	$(SOURCES:.c=.o)
CC	=	gcc	-Wall -Wextra -Werror -g -I./

all:		$(NAME)

$(NAME):	$(OBJECTS)
			ar rcs $(NAME) $(OBJECTS)

clean:		
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re