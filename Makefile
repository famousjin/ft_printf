# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myyou <myyou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 12:22:54 by myyou             #+#    #+#              #
#    Updated: 2022/07/08 13:10:19 by myyou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	= ft_printf.c \
		  ft_utile1.c \
		  ft_utile2.c \

OBJS_FILES   = ${SRCS_FILES:.c=.o}
NAME   = libftprintf.a
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
RM	   = rm -f

all: ${NAME}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME): ${OBJS_FILES}
	make -C libft
	mv libft/libft.a $(NAME)
	ar -rcs $(NAME) ${OBJS_FILES}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME)
	make fclean -C libft

re: fclean all

m: re
	gcc *.o -lftprintf -L.
	./a.out

.PHONY: all clean fclean re
