# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 16:13:23 by ddantas-          #+#    #+#              #
#    Updated: 2023/01/14 19:40:40 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
RM = rm

FILESC = push_swap.c 

OBJS = $(FILESC:.c=.o)


FT_PRINTF = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) 

$(FT_PRINTF):
	$(MAKE) -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(NAME).o
	$(RM) -f ./obj/*.o
	$(MAKE) -C ft_printf fclean
	
fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re