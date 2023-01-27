/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 19:18:18 by ddantas-         ###   ########.fr       */
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
t_alist *create_list(t_alist *lst, int *stack, int argc);
void	ft_freelist(t_alist* head);
int		ft_lstsize_2(t_alist *lst);
t_alist	*ft_add_lst(t_alist *lst, int atoi, int p);

/*		protection.c		*/
void	free_stuff(t_alist *lst, int *stack_a, int *stack_b, int error);
int		already_sorted(t_alist *lst, int *stack_a, int argc, int n);
int		check_n(t_alist *lst, char *str, int *stack_a, int *stack_b);
int		duplicate_check(t_alist *lst, int *stack_a, int *stack_b, int n);
int		*protection(t_alist *lst, int *stack_a, int argc, char **argv);

/*		operations.c		*/
int		sa(int *stack_a, int ss);
int		sb(int *stack_b, int ss);
int		ss(int *stack_a, int *stack_b);

#endif