/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 16:26:28 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack_a;
	t_alist		*lst;
	//t_b_list	list_b;
	
	// List experiment
	lst = (t_alist *)malloc(sizeof(t_alist));
	if (!lst)
		free(lst);
	lst->data = 1;
	lst->next = NULL;
	ft_printf("list size = %d\n", ft_lstsize_2(lst));
	ft_printf("lst.data = %d | lst.next = %p\n", lst->data, lst->next);
	// List experiment End
	
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(stack_a, 0, 1);	
	protection(lst, stack_a, argc, argv);
	free(stack_a);

	ft_printf("Ready to be sorted!\n");

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
