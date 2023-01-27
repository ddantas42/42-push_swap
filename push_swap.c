/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 13:24:27 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack_a;
	int			n;
	t_alist		*first;
	//t_b_list	list_b;
	
	// List experiment
	first = (t_alist *)malloc(sizeof(t_alist));
	if (!first)
		free(first);
	first->data = 1;
	first->next = NULL;
	int size_list = ft_lstsize_2(first);
	ft_printf("size_list = %d\n", size_list);
	ft_printf("first.data = %d | first.next = %p\n", first->data, first->next);
	// List experiment End
	
	
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(stack_a, 0, 1);	
	protection(stack_a, argc, argv);

	// AFTER PROTECTION FREE STACK_A free(stack_a);

	// print Stack 
	ft_printf("Stack: A\n");
	n = 0;
	while (n < argc - 1)
		ft_printf("%d\n", stack_a[n++]);
	ft_printf("_\n");
	// Print Stack End
	
	free_stuff(stack_a, 0, 0);
	return (0);
}
