#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 17:32:02 by gboudrie          #+#    #+#              #
#    Updated: 2016/06/07 15:31:35 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

MKLIB = make -C libft/

INCLUDES = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = event.c segment.c reader.c main.c drawer.c rotation.c

OBJS = $(SOURCES:.c=.o)

MLX = -lmlx -framework OpenGL -framework AppKit

all :			$(NAME)

$(NAME) :
				$(MKLIB)
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)


fonly :
				$(CC) $(FLAGS) -c $(SOURCES)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(MLX)

norm :
				norminette $(SOURCES)

meteo :
				curl http://wttr.in/Paris
				curl http://wttr.in/Moon

clean :
				-rm -f $(OBJS)

fclean :		clean
				$(MKLIB) fclean
				-rm -f $(NAME)

re :			fclean all