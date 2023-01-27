/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:40:42 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 16:26:27 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int sa(int *stack_a, int ss)
{
	int	buffer;

	if ((stack_a[0] || stack_a[0] == 0) &&
		(stack_a[1] || stack_a[1] == 0))
	{
		buffer = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = buffer;
		if (ss == 0)
			ft_printf("sa\n");
	}
	return (0);
}

int sb(int *stack_b, int ss)
{
	int	buffer;

	if ((stack_b[0] || stack_b[0] == 0) &&
		(stack_b[1] || stack_b[1] == 0))
	{
		buffer = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = buffer;
		if (ss == 0)
			ft_printf("sb\n");
	}
	return (0);
}

int ss(int *stack_a, int *stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
	return (0);
}
