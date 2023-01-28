/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/28 16:50:01 by ddantas-         ###   ########.fr       */
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
void	pop_top_a(t_alist **alst);
void	pop_top_b(t_blist **blst);
void	ft_freelist(t_alist *alst, t_blist *blst, int malloc);
int		ft_lstsize_2(t_alist *alst, t_blist *blst);
t_alist	*ft_add_alst(t_alist *alst, t_blist *blst, int atoi);

/*		protection.c		*/
void	free_stuff(t_alist *lst, int *stack_a, int *stack_b, int error);
int		already_sorted(t_alist *lst, int *stack_a, int argc, int n);
int		check_n(t_alist *lst, char *str, int *stack_a, int *stack_b);
int		duplicate_check(t_alist *lst, int *stack_a, int *stack_b, int n);
int		*protection(t_alist *lst, int *stack_a, int argc, char **argv);

/*		operations.c		*/
t_alist	*sa(t_alist	*alst, int ss);
t_blist	*sb(t_blist *blst, int ss);
t_alist	*ss(t_alist *alst, t_blist *blst);
void	pa(t_blist **blst, t_alist **alst, int data);
void	pb(t_blist **blst, t_alist **alst, int data);


#endif