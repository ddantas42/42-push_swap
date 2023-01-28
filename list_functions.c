/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:33:54 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/28 15:14:03 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_top_a(t_alist **alst)
{
    t_alist	*temp;

	if (alst == NULL)
		exit(1);
	else
	{
		temp = (*alst);
    	(*alst) = (*alst)->next;
		free(temp);
	}
}

void	ft_freelist(t_alist *alst, t_blist *blst, int malloc)
{
	t_alist	*temp_a;
	t_blist	*temp_b;

	if (malloc == 1)
	{
		free(alst);
		exit(EXIT_FAILURE);
	}
	while (alst != NULL)
	{
		temp_a = alst;
		alst = alst->next;
		free(temp_a);
	}
	if (malloc == 2)
	{
		free(blst);
		exit(EXIT_FAILURE);
	}
	while (blst != NULL)
	{
		temp_b = blst;
		blst = blst->next;
		free(temp_b);
	}
	alst = NULL;
	blst = NULL;
	exit(EXIT_FAILURE);
}

t_alist	*ft_add_alst(t_alist *alst, t_blist *blst, int atoi)
{
	t_alist *new;
	t_alist	*temp;

	temp = alst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;	
	new = (t_alist *)malloc(sizeof(new));
	if (!new)
	{
		free(new);	
		ft_freelist(alst, blst, 0);
	}
	new->data = atoi;
	new->next = NULL;
	if (temp != NULL)
		temp->next = new;
	else
		alst = new;
	return (alst);
}

t_blist	*ft_add_blst(t_alist *alst, t_blist *blst, int atoi)
{
	t_blist *new;
	t_blist	*temp;

	temp = blst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;	
	new = (t_blist *)malloc(sizeof(new));
	if (!new)
	{
		free(new);	
		ft_freelist(alst, blst, 0);
	}
	new->data = atoi;
	new->next = NULL;
	if (temp != NULL)
		temp->next = new;
	else
		blst = new;
	return (blst);
}

int	ft_lstsize_2(t_alist *alst, t_blist *blst)
{
	int	n;

	n = 0;
	if (alst)
	{
		while (alst)
		{
			n++;
			alst = alst->next;
		}
	}
	if (blst)
	{
		while (blst)
		{
			n++;
			blst = blst->next;
		}
	}
	ft_printf("n = %d\n", n);
	return (n);
}