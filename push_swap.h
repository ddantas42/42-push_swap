/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/29 15:21:31 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct ps_list
{
	int				data;
	struct ps_list	*next;
}					t_ps_list;

/*		list_functions.c	*/
void		pop_top_a(t_ps_list **alst);
void		pop_top_b(t_ps_list **blst);
void		ft_freelist(t_ps_list *alst, t_ps_list *blst, int malloc);
int			ft_lstsize_2(t_ps_list *alst, t_ps_list *blst);
t_ps_list	*ft_add_alst(t_ps_list **alst, t_ps_list *blst, int atoi);

/*		list_utils.c		*/

/*		protection.c		*/
void		free_stuff(t_ps_list *lst, int *stack_a, int *stack_b, int error);
int			already_sorted(t_ps_list *lst, int *stack_a, int argc, int n);
int			check_n(t_ps_list **lst, char *str, int *stack_a, int *stack_b);
int			duplicate_check(t_ps_list *lst, int *stack_a, int *stack_b, int n);
int			*protection(t_ps_list **lst, int *stack_a, int argc, char **argv);

/*		operations.c		*/
t_ps_list	*sa(t_ps_list	*alst, int ss);
t_ps_list	*sb(t_ps_list *blst, int ss);
t_ps_list	*ss(t_ps_list *alst, t_ps_list *blst);
void		pa(t_ps_list **blst, t_ps_list **alst);
void		pb(t_ps_list **blst, t_ps_list **alst);

#endif