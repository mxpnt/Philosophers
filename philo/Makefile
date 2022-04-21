# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 18:12:35 by maxime            #+#    #+#              #
#    Updated: 2022/03/21 09:43:13 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INC		=	inc/philo.h

SRC		=	main.c \
			init.c \
			error.c \
			parsing.c \
			utils.c

SRCS	=	${addprefix src/, ${SRC}}

OBJS	=	${addprefix objs/, ${SRCS:.c=.o}}

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all:		${NAME}
objs/%.o:	%.c ${INC} Makefile
			@mkdir -p ${dir $@}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS} ${INC}
			${CC} ${CFLAGS} -pthread -o ${NAME} ${OBJS}

clean:		
			rm -rf objs/

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
