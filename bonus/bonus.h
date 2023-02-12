/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:30:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/12 14:46:08 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>
# include <limits.h>


typedef struct bonus_list
{
	int				data;
	int				pos;
	struct bonus_list	*next;
}					t_bonus_list;

/*		b_atoi.c			*/
int				ft_atoi_while_1(const char *str);
int				ft_atoi_if(const char *str, int *n);
int				ft_atoi(const char *str, t_bonus_list **lst, int *stack_a, int *stack_b);


/*		b_list_f.c			*/
void			ft_freelist(t_bonus_list *alst, t_bonus_list *blst, int malloc);
void			ft_freelist_2(t_bonus_list *blst, int error);
t_bonus_list	*ft_add_alst(t_bonus_list **alst, t_bonus_list *blst, int atoi);

/*		b_protection.c		*/
int				check_n(t_bonus_list **lst, char *str, int *stack_a, int *stack_b);
int				duplicate_check(t_bonus_list *lst, int *stack_a, int *stack_b, int argc);
int				*protection(t_bonus_list **lst, int *stack_a, int argc, char **argv);


/*			bonus.c			*/
void			free_stuff(t_bonus_list *lst, int *stack_a, int *stack_b, int error);

#endif