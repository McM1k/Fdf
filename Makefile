#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 17:32:02 by gboudrie          #+#    #+#              #
#    Updated: 2016/03/15 17:47:31 by gboudrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

MKLIB = libft/Makefile

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all :			$(NAME)

$(NAME) :		$(MKLIB)

clean :			

fclean :		

re :			