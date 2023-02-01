/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:22:56 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/01 16:53:31 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	both_s(t_ps_list **alst, t_ps_list **blst)
{	
	if ((*alst) != NULL && (*blst) != NULL)
	{
		if ((*alst)->next != NULL && (*blst)->next != NULL)
		{
			if (((*alst)->data > (*alst)->next->data)
				&& (*blst)->data > (*blst)->data)
				ss(*alst, *blst);
		}
	}
	if ((*alst) != NULL && (*alst)->next != NULL
		&& ((*alst)->data > (*alst)->next->data))
		sa(*alst, 0);
	if ((*blst) != NULL && (*blst)->next != NULL
		&& ((*blst)->data > (*blst)->next->data))
		sb(*blst, 0);
	pb(alst, blst);
	is_it_sorted(alst, blst);
	return (0);
}

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

void	algorithm(t_ps_list *alst, t_ps_list *blst)
{
	is_it_sorted(&alst, &blst);
	while (1)
	{
		sleep(1);
		print_list_a(alst);
		
		is_both_sorted(&alst, &blst);
		both_s(&alst, &blst);
		rra(&alst, 0);
		is_it_sorted(&alst, &blst);
	}
}
