/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:42:28 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:56:11 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_it_sorted(t_ps_list **alst, t_ps_list **blst)
{
	t_ps_list	*temp;

	is_both_sorted(alst, blst);
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
	ft_freelist(*alst, *blst, 0);
}

void	just_pa(t_ps_list **alst, t_ps_list **blst)
{
	while ((*blst))
		pa(blst, alst);
	ft_freelist(*alst, *blst, 0);
}

void	is_both_sorted(t_ps_list **alst, t_ps_list **blst)
{
	t_ps_list	*temp;

	if (*blst == NULL)
		return ;
	temp = (*alst);
	while (temp->next)
	{
		if (temp == NULL || temp->next == NULL)
			break ;
		if (temp->data > temp->next->data)
			return ;
		temp = temp->next;
	}
	temp = (*blst);
	while (temp->next)
	{
		if (temp->next == NULL)
			break ;
		if (temp->data < temp->next->data)
			return ;
		temp = temp->next;
	}
	if ((*alst) && ((*alst)->data < (*blst)->data))
		return ;
	just_pa(alst, blst);
}
