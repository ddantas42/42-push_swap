/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:22:56 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/02 15:49:51 by ddantas-         ###   ########.fr       */
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

void	algorithm_3(t_ps_list *alst, int argc)
{
	if (argc == 2 || (alst->data > alst->next->data
			&& alst->next->data < alst->next->next->data))
		sa(alst, 0);
	else if (alst->data > alst->next->data
			&& alst->next->data < alst->next->next->data)
		ra(&alst, 0);
	else if (alst->data < alst->next->data
			&& alst->next->data > alst->next->next->data)
	{
		rra(&alst, 0);
		sa(alst, 0);
	}
	else if (alst->data < alst->next->data
			&& alst->next->data > alst->next->next->data)
		rra(&alst, 0);
		
}
