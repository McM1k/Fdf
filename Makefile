#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 17:32:02 by gboudrie          #+#    #+#              #
#    Updated: 2016/03/17 19:55:27 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

MKLIB = make -C libft/

INCLUDES = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = reader.c main.c

OBJS = $(SOURCES:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all :			$(NAME)

$(NAME) :
				$(MKLIB)
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)

norm :
				norminette $(SOURCES)

meteo :
				curl http://wttr.in/Paris

clean :
				-rm -f $(OBJS)

fclean :		clean
				$(MKLIB) fclean
				-rm -f $(NAME)

re :			fclean all