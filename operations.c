/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 07:40:04 by  ddantas-         #+#    #+#             */
/*   Updated: 2023/01/28 18:35:37 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alist	*sa(t_alist	*alst, int ss)
{
	int		n_temp;

	if (ss == 0)
		ft_printf("sa\n");
	if (alst != NULL && alst->next != NULL)
	{
		n_temp = alst->next->data;
		alst->next->data = alst->data;
		alst->data = n_temp;
	}
	return (alst);
}

t_blist	*sb(t_blist *blst, int ss)
{
	int		n_temp;

	if (ss == 0)
		ft_printf("sb\n");
	if (blst != NULL && blst->next != NULL)
	{
		n_temp = blst->next->data;
		blst->next->data = blst->data;
		blst->data = n_temp;
	}
	return (blst);
}

t_alist	*ss(t_alist *alst, t_blist *blst)
{
	alst = sa(alst, 1);
	blst = sb(blst, 1);
	ft_printf("ss\n");
	return (0);
}

void	pa(t_blist **blst, t_alist **alst, int data)
{
	t_alist	*new;

	new = (t_alist *)malloc(sizeof(t_alist));
	if (!new)
	{
		free(new);
		ft_freelist((*alst), (*blst), 0);
	}
	new->data = data;
	new->next = (*alst);
	(*alst) = new;
	pop_top_b(blst);
	ft_printf("pa\n");
}

void	pb(t_blist **blst, t_alist **alst, int data)
{
	t_blist	*new;
	//static int first = 0;

	/*if (first == 0)
	{
		first++;
		
		(*blst)->data = data;
		pop_top_a(alst);
		return ;
	}*/
	new = (t_blist *)malloc(sizeof(t_blist));
	if (!new)
	{
		free(new);
		ft_freelist((*alst), (*blst), 0);
	}
	new->data = data;
	new->next = (*blst);
	(*blst) = new;
	pop_top_a(alst);
	ft_printf("pb\n");
}
