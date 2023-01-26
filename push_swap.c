/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/26 21:34:21 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	n;

	stack_a = (int *)malloc(argc * sizeof(int));
	stack_b = (int *)malloc(argc * sizeof(int));
	protection(stack_a, stack_b, argc, argv);
	ft_printf("Stack: A\n");
	n = 0;
	while (stack_a[n])
		ft_printf("%d\n", stack_a[n++]);
	ft_printf("_\n");
	free_stuff(stack_a, stack_b, 0);
	return (0);
}
