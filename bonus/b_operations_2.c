/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:16:57 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 11:26:32 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ra(t_bonus_list **alst)
{
	t_bonus_list	*temp;

	if ((*alst) == NULL || (*alst)->next == NULL)
		return ;
	temp = (*alst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*alst);
	*alst = (*alst)->next;
	temp->next->next = NULL;
}

void	rb(t_bonus_list **blst)
{
	t_bonus_list	*temp;

	if ((*blst) == NULL || (*blst)->next == NULL)
		return ;
	temp = (*blst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*blst);
	*blst = (*blst)->next;
	temp->next->next = NULL;
}

void	rr(t_bonus_list **alst, t_bonus_list **blst)
{
	ra(alst);
	rb(blst);
}

void	rra(t_bonus_list **alst)
{
	t_bonus_list	*temp;

	if ((*alst) == NULL || (*alst)->next == NULL)
		return ;
	temp = (*alst);
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = (*alst);
	(*alst) = temp->next;
	temp->next = NULL;
}

void	rrb(t_bonus_list **blst)
{
	t_bonus_list	*temp;

	if ((*blst) == NULL || (*blst)->next == NULL)
		return ;
	temp = (*blst);
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = (*blst);
	(*blst) = temp->next;
	temp->next = NULL;
}
