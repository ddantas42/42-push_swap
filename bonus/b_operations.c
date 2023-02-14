/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:10:29 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:00:03 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_bonus_list	*sa(t_bonus_list *alst)
{
	int		n_temp;
	int		pos_temp;

	if (alst == NULL || alst->next == NULL)
		return (alst);
	if (alst != NULL && alst->next != NULL)
	{
		n_temp = alst->next->data;
		pos_temp = alst->next->pos;
		alst->next->data = alst->data;
		alst->next->pos = alst->pos;
		alst->data = n_temp;
		alst->pos = pos_temp;
	}
	return (alst);
}

t_bonus_list	*sb(t_bonus_list *blst)
{
	int		n_temp;
	int		pos_temp;

	if (blst == NULL || blst->next == NULL)
		return (blst);
	if (blst != NULL && blst->next != NULL)
	{
		n_temp = blst->next->data;
		pos_temp = blst->next->pos;
		blst->next->data = blst->data;
		blst->next->pos = blst->pos;
		blst->data = n_temp;
		blst->pos = pos_temp;
	}
	return (blst);
}

t_bonus_list	*ss(t_bonus_list *alst, t_bonus_list *blst)
{
	alst = sa(alst);
	blst = sb(blst);
	return (0);
}

void	pa(t_bonus_list **blst, t_bonus_list **alst)
{
	t_bonus_list	*temp;

	if (*blst == NULL)
		return ;
	if (*alst == NULL)
	{
		temp = (*blst)->next;
		(*alst) = (*blst);
		(*alst)->next = NULL;
		(*blst) = temp;
	}
	else
	{
		temp = (*alst);
		(*alst) = (*blst);
		(*blst) = (*blst)->next;
		(*alst)->next = temp;
	}
}

void	pb(t_bonus_list **blst, t_bonus_list **alst)
{
	t_bonus_list	*temp;

	if (*alst == NULL)
		return ;
	if (*blst == NULL)
	{
		temp = (*alst)->next;
		(*blst) = (*alst);
		(*blst)->next = NULL;
		(*alst) = temp;
	}
	else
	{
		temp = (*blst);
		(*blst) = (*alst);
		(*alst) = (*alst)->next;
		(*blst)->next = temp;
	}
}