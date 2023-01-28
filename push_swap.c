/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/28 18:39:45 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_a(t_alist *lst)
{
	t_alist *temp = lst;
	ft_printf("A\n");
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
	}
	ft_printf("_\n\n");
}


void	print_list_b(t_blist *lst)
{
	t_blist *temp = lst;
	ft_printf("B\n");
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
		
	}
	ft_printf("_\n\n");
}

/*void	bye_0_blst(t_blist **blst, t_alist **alst)
{
	t_blist	*new;

	new = (t_blist *)malloc(sizeof(t_blist));
	if (!new)
	{
		free(new);
		ft_freelist((*alst), (*blst), 0);
	}
	new->data = 1;
	new->next = (*blst);
	(*blst) = new;
}*/

int	main(int argc, char **argv)
{
	int			*stack_a;
	t_alist		*alst;
	t_blist		*blst;
	
	alst = (t_alist *)malloc(sizeof(t_alist));
	if (!alst)
		ft_freelist(alst, 0, 1);
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);	
	protection(alst, stack_a, argc, argv);
	pop_top_a(&alst);
	
	blst = (t_blist *)malloc(sizeof(t_blist));
	if (!blst)
		ft_freelist(alst, blst, 2);
	
	print_list_a(alst);
	int	c;
	scanf("%d", &c);
	//bye_0_blst(&blst, &alst);
	while (c)
	{
		if (argc - 1 != ft_lstsize_2(alst,0) && c == 1)
			pa(&blst, &alst, blst->data);
		if (argc - 1 != ft_lstsize_2(0,blst) && c == 2)
			pb(&blst, &alst, alst->data);
		if (c == 3)
			sa(alst, 0);
		if (c == 4)
			sb(blst, 0);
		if (c == 5)
			pop_top_b(&blst);
		print_list_a(alst);
		print_list_b(blst);
		scanf("%d", &c);
	}

	
	ft_freelist(alst, blst, 0);
	ft_printf("Ready to be sorted!\n");
	return (0);
}
