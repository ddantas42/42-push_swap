/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:19:49 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/26 19:27:28 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

/*		protection.c		*/
void	free_stuff(int *stack_a, int *stack_b);
int		check_n(char *str, int *stack_a, int *stack_b);
int		*protection(int *stack_a, int *stack_b, int argc, char **argv);
void	duplicate_check(int *stack_a, int *stack_b, int n);

#endif