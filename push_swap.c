/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/29 15:24:12 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_a(t_ps_list *lst)
{
	t_ps_list *temp = lst;
	ft_printf("A\n");
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
	}
	ft_printf("_\n\n");
}


void	print_list_b(t_ps_list *lst)
{
	t_ps_list *temp = lst;
	ft_printf("B\n");
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
		
	}
	ft_printf("_\n\n");
}

int	main(int argc, char **argv)
{
	int			*stack_a;
	t_ps_list		*alst;
	t_ps_list		*blst;
	
	alst = 0;
	blst = 0;
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);	
	protection(&alst, stack_a, argc, argv);
	print_list_a(alst);
	int	c;	scanf("%d", &c);
	while (c)
	{
		ft_printf("argc = %d\n", argc);
		if (c == 1)
			pa(&blst, &alst);
		if (c == 2)
			pb(&blst, &alst);
		if (c == 3)
			sa(alst, 0);
		if (c == 4)
			sb(blst, 0);
		print_list_a(alst);
		print_list_b(blst);
		scanf("%d", &c);
	}

	
	ft_freelist(alst, blst, 0);
	ft_printf("Ready to be sorted!\n");
	return (0);
}
