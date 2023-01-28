/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/28 09:21:11 by ddantas-         ###   ########.fr       */
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
		ft_freelist(lst);
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(lst, stack_a, 0, 1);	
	protection(lst, stack_a, argc, argv);
	free(stack_a);
	lst = pop_top(lst);
	t_alist *temp = lst;
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
	}
	ft_freelist(lst);

	ft_printf("Ready to be sorted!\n");
	return (0);
}
