# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phil <phil@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 16:44:42 by phil              #+#    #+#              #
#    Updated: 2021/10/13 16:49:27 by phil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC		=	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_convert.c \

OBJECTS		=	${SRC:.c=.o}

HEADERS = ft_printf.h

CC			=	gcc

RM			=	rm -f

CC_FLAGS	=	-Wall -Werror -Wextra

${NAME}:
			@${CC} -g ${CFLAGS} -c ${SRC}
			@ar crs ${NAME} ${OBJECTS}

all:		${NAME}

fclean:		clean
			@${RM} ${NAME}
.c.o:
			@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

clean:
			@${RM} ${OBJECTS}

re:			fclean all

.PHONY:		all clean fclean re

xtest:		fclean
			${RM} a.out

test:		fclean all
			@cc -g testes.c libftprintf.a && ./a.out

debug:		fclean all
			@cc -g testes.c libftprintf.a
