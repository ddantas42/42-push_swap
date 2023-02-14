/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:30:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 12:45:06 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <limits.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define READ_MORE 100

typedef struct bonus_list
{	
	int					data;
	int					pos;
	struct bonus_list	*next;
}					t_bonus_list;

/*		b_atoi.c			*/
int				ft_atoi_while_1(const char *str);
int				ft_atoi_if(const char *str, int *n);
int				ft_atoi(const char *str, t_bonus_list **lst,
					int *stack_a, int *stack_b);

/*		b_list_f.c			*/
void			ft_freelist(t_bonus_list *alst, t_bonus_list *blst, int malloc);
void			ft_freelist_2(t_bonus_list *blst, int error);
t_bonus_list	*ft_add_alst(t_bonus_list **alst, t_bonus_list *blst, int atoi);

/*		b_operations.c		*/
t_bonus_list	*sa(t_bonus_list *alst);
t_bonus_list	*sb(t_bonus_list *blst);
t_bonus_list	*ss(t_bonus_list *alst, t_bonus_list *blst);
void			pa(t_bonus_list **blst, t_bonus_list **alst);
void			pb(t_bonus_list **blst, t_bonus_list **alst);

/*		b_operations_2.c		*/
void			ra(t_bonus_list **alst);
void			rb(t_bonus_list **blst);
void			rr(t_bonus_list **alst, t_bonus_list **blst);
void			rra(t_bonus_list **alst);
void			rrb(t_bonus_list **blst);

/*		b_protection.c		*/
int				check_n(t_bonus_list **lst, char *str,
					int *stack_a, int *stack_b);
int				duplicate_check(t_bonus_list *lst, int *stack_a,
					int *stack_b, int argc);
int				*protection(t_bonus_list **lst, int *stack_a,
					int argc, char **argv);

/*			bonus.c			*/
void			free_stuff(t_bonus_list *lst, int *stack_a,
					int *stack_b, int error);
void			rrr(t_bonus_list **alst, t_bonus_list **blst);

/*			handler.c		*/
char			set_zero(char str[]);
int				select_arg(char str[]);
void			exec_arg(int arg, t_bonus_list **alst, t_bonus_list **blst);
int				input_handler(t_bonus_list **alst, t_bonus_list **blst);

#endif