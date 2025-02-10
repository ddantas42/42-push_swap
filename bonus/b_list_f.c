/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_list_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:06:23 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:51:47 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_freelist(t_bonus_list *alst, t_bonus_list *blst, int malloc)
{
	t_bonus_list	*temp_a;

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
	ft_freelist_2(blst, malloc);
}

void	ft_freelist_2(t_bonus_list *blst, int error)
{
	t_bonus_list	*temp_b;

	if (error == 2)
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
	if (error == 3)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

t_bonus_list	*ft_add_alst(t_bonus_list **alst, t_bonus_list *blst, int atoi)
{
	t_bonus_list	*new;
	t_bonus_list	*temp;

	temp = *alst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	new = (t_bonus_list *)malloc(sizeof(t_bonus_list));
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
 