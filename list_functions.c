/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:33:54 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/29 15:31:18 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_top_a(t_ps_list **alst)
{
	t_ps_list	*temp;

	if (alst == NULL)
		exit(1);
	else
	{
		temp = (*alst);
		(*alst) = (*alst)->next;
		free(temp);
	}
}

void	pop_top_b(t_ps_list **blst)
{
	t_ps_list	*temp;

	if (blst == NULL)
		exit(1);
	else
	{
		temp = (*blst);
		(*blst) = (*blst)->next;
		free(temp);
	}
}

void	ft_freelist(t_ps_list *alst, t_ps_list *blst, int malloc)
{
	t_ps_list	*temp_a;
	t_ps_list	*temp_b;

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
	exit(EXIT_FAILURE);
}

t_ps_list	*ft_add_alst(t_ps_list **alst, t_ps_list *blst, int atoi)
{
	t_ps_list	*new;
	t_ps_list	*temp;

	temp = *alst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	new = (t_ps_list *)malloc(sizeof(t_ps_list));
	if (!new)
	{
		free(new);
		ft_freelist(*alst, blst, 0);
	}
	new->data = atoi;
	new->next = NULL;
	if (temp != NULL)
		temp->next = new;
	else
		*alst = new;
	return (0);
}

int	ft_lstsize_2(t_ps_list *alst, t_ps_list *blst)
{
	int	n;

	n = 0;
	if (alst != NULL)
	{
		while (alst != NULL)
		{
			n++;
			alst = alst->next;
		}
	}
	if (blst != NULL)
	{
		while (blst != NULL)
		{
			n++;
			blst = blst->next;
		}
	}
	return (n);
}
