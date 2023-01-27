/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 11:59:45 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			n;
	//t_a_list	list_a;
	//t_b_list	list_b;
	
	
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(stack_a, 0, 2);	
	protection(stack_a, argc, argv);
	ft_printf("Stack: A\n");
	n = 0;
	while (n < argc - 1)
		ft_printf("%d\n", stack_a[n++]);
	ft_printf("_\n");
	free_stuff(stack_a, 0, 0);
	return (0);
}
