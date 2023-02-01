/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:42:28 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/01 16:54:22 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_it_sorted(t_ps_list **alst, t_ps_list **blst)
{
	t_ps_list	*temp;

	temp = (*alst);
	if (*blst != NULL)
		return ;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break ;
		if (temp->data > temp->next->data)
			return ;
		temp = temp->next;
	}
	ft_printf("Sorted! :D\n");
	ft_freelist(*alst, *blst, 0);
}

void		just_pa(t_ps_list **alst, t_ps_list **blst)
{
	while (blst != NULL)
	{
		pa(alst, blst);
		(*blst) = (*blst)->next;
	}
	is_it_sorted(alst, blst);
}

void	is_both_sorted(t_ps_list **alst, t_ps_list **blst)
{
	t_ps_list	*temp;

	temp = (*alst);
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		if (temp->data > temp->next->data)
			return ;
		temp = temp->next;
	}
	temp = (*blst);
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		if (temp->data < temp->next->data)
			return ;
		temp = temp->next;
	}
	just_pa(alst, blst);
}