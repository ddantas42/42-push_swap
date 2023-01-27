/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 16:24:35 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack_a;
	t_alist		*lst;
	//t_b_list	list_b;
	
	lst = (t_alist *)malloc(sizeof(t_alist));
	if (!lst)
		free(lst);
	lst->data = 1;
	lst->next = NULL;
	ft_printf("list size = %d\n", ft_lstsize_2(lst));
	ft_printf("lst.data = %d | lst.next = %p\n", lst->data, lst->next);
	
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(stack_a, 0, 1);	
	protection(stack_a, argc, argv);
	free(stack_a);

	// List experiment
	// List experiment End

	ft_printf("Ready to be sorted!\n");
	// AFTER PROTECTION FREE STACK_A free(stack_a);

	/* 
	// print Stack 
	ft_printf("Stack: A\n");
	int n = 0;
	while (n < argc - 1)
		ft_printf("%d\n", stack_a[n++]);
	ft_printf("_\n");
	// Print Stack End */
	free(lst);
	return (0);
}
