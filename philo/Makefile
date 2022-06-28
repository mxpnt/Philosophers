# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 18:12:35 by maxime            #+#    #+#              #
#    Updated: 2022/05/11 13:35:44 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

INC		=	inc/philo.h

SRC		=	main.c \
			action.c \
			error.c \
			free.c \
			init.c \
			launcher.c \
			parsing.c \
			sleeping.c \
			utils.c \
			utils2.c

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
