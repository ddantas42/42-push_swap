/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/15 13:01:23 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>

typedef struct ps_list
{
	int				data;
	int				pos;
	struct ps_list	*next;
}					t_ps_list;

/*		algorithm.c			*/
t_ps_list		*algorithm_3(t_ps_list *alst, int argc);

/*		list_functions.c	*/
void		ft_freelist(t_ps_list *alst, t_ps_list *blst, int malloc);
void		ft_freelist_2(t_ps_list *blst, int error);
t_ps_list	*ft_add_alst(t_ps_list **alst, t_ps_list *blst, int atoi);

/*		main_algo.c			*/
void		main_algorithm(t_ps_list *alst, t_ps_list *blst, int lstsize);

/*		pa_algo.c			*/
void		locate_higher_2(t_ps_list **blst, int higher_pos,
				int n, int temp_n);
void		locate_higher(t_ps_list **blst, int higher_pos);
void		pa_algo(t_ps_list **alst, t_ps_list **blst, int lstsize);

/*		pb_algo.c			*/
void		locate_closer(t_ps_list **alst, int min_pos,
				int div, int lstsize);
void		pb_algo(t_ps_list **alst, t_ps_list **blst,
				int divide, int lstsize);

/*		protection.c		*/
void		free_stuff(t_ps_list *lst, int *stack_a, int *stack_b, int error);
int			check_n(t_ps_list **lst, char *str, int *stack_a, int *stack_b);
int			duplicate_check(t_ps_list *lst, int *stack_a, int *stack_b, int n);
int			*protection(t_ps_list **lst, int *stack_a, int argc, char **argv);

/*		operations.c		*/
t_ps_list	*sa(t_ps_list	*alst, int ss);
t_ps_list	*sb(t_ps_list *blst, int ss);
void		pa(t_ps_list **blst, t_ps_list **alst);
void		pb(t_ps_list **blst, t_ps_list **alst);

/*		operations_2.c		*/
void		ra(t_ps_list **alst, int rr);
void		rb(t_ps_list **blst, int rr);
void		rra(t_ps_list **alst, int rrr);
void		rrb(t_ps_list **blst, int rrr);

/*		push_swap.utils.c	*/
int			ft_atoi_while_1(const char *str);
int			ft_atoi_if(const char *str, int *n);
int			ft_atoi(const char *str, t_ps_list **lst,
				int *stack_a, int *stack_b);

/*		push_swap.c			*/
t_ps_list	*ss(t_ps_list *alst, t_ps_list *blst);
void		rr(t_ps_list **alst, t_ps_list **blst);
void		rrr(t_ps_list **alst, t_ps_list **blst);

/*		sorted.c			*/
void		just_pa(t_ps_list **alst, t_ps_list **blst);
void		is_it_sorted(t_ps_list **alst, t_ps_list **blst);
void		is_both_sorted(t_ps_list **alst, t_ps_list **blst);

#endif