/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:35:55 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/07 16:16:01 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	locate_higher(t_ps_list **blst, int higher_pos)
{
	int			n;
	t_ps_list	*temp;
	
	temp = *blst;
	n = 0;
	while (temp)
	{
		if (temp->pos == higher_pos)
			break ;
		n++;
		temp = temp->next;
	}
	if (n > higher_pos / 2)
	{
		while (n--)
			rb(blst, 0);
	}
	else 
		while (n--)
			rrb(blst, 0);
		
}

void	pa_algo(t_ps_list **alst, t_ps_list **blst, int lstsize)
{
	while (lstsize)
	{
		if ((*blst)->pos == lstsize)
		{
			pa(blst, alst);
			lstsize--;
		}
		locate_higher(blst, lstsize);
	}
}
