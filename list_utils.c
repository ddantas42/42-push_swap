/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:09:11 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/29 15:20:18 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_blist	*ft_add_blst(t_alist *alst, t_blist *blst, int atoi)
{
	t_blist	*new;
	t_blist	*temp;

	temp = blst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	new = (t_blist *)malloc(sizeof(t_blist));
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