# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 16:13:23 by ddantas-          #+#    #+#              #
#    Updated: 2023/01/26 19:37:18 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -g #-Werror
NAME = push_swap
RM = rm

FILESC = push_swap.c protection.c

OBJS = $(FILESC:.c=.o)


FT_PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a


all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF) 

$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft re

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(OBJS)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	
fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re