# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 16:13:23 by ddantas-          #+#    #+#              #
#    Updated: 2023/02/12 16:24:17 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra #-Werror
NAME = push_swap
RM = rm

FILESC = push_swap.c protection.c operations.c \
		list_functions.c operations_2.c algorithm.c \
		sorted.c push_swap_utils.c main_algo.c pb_algo.c pa_algo.c

OBJS = $(FILESC:.c=.o)

BONUS = checker
BONUS_FILES = ./bonus/bonus.c ./bonus/b_protection.c ./bonus/b_list_f.c \
			./bonus/b_atoi.c
BONUS_OBJS = $(BONUS_FILES:.c=.o)

FT_PRINTF = ./ft_printf/libftprintf.a
GET_NEXT_LINE = ./get_next_line/get_next_line.a

all: $(BONUS) $(NAME)

$(NAME): $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) 

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(FT_PRINTF)


$(FT_PRINTF):
	$(MAKE) -C ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(BONUS_OBJS)
	$(MAKE) -C ft_printf fclean
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all


.PHONY: all clean fclean re bonus