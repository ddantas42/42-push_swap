/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 13:26:15 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct a_list
{
	int				data;
	struct a_list	*next;
}					t_alist;

typedef struct b_list
{
	int				data;
	struct b_list	*next;
}					t_blist;

/*		list_functions.c	*/
int		ft_lstsize_2(t_alist *lst);

/*		protection.c		*/
void	free_stuff(int *stack_a, int *stack_b, int error);
int		already_sorted(int *stack_a, int *stack_b, int argc, int n);
int		check_n(char *str, int *stack_a, int *stack_b);
void	duplicate_check(int *stack_a, int *stack_b, int n);
int		*protection(int *stack_a, int argc, char **argv);

/*		operations.c		*/
int		sa(int *stack_a, int ss);
int		sb(int *stack_b, int ss);
int		ss(int *stack_a, int *stack_b);

#endif