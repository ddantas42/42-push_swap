/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:35:55 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/10 14:33:24 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	locate_higher_2(t_ps_list **blst, int higher_pos, int n, int temp_n)
{
	if (n > higher_pos / 2)
	{
		temp_n = (higher_pos / 2);
		if (temp_n <= -1)
			return ;
		while (temp_n--)
		{
			if (temp_n < 0)
				break ;
			if ((*blst)->pos == higher_pos)
				break ;
			rrb(blst, 0);
		}
	}
	else
	{
		while (n--)
		{
			if ((*blst)->pos == higher_pos)
				break ;
			rb(blst, 0);
		}
	}
}

void	locate_higher(t_ps_list **blst, int higher_pos)
{
	int			n;
	int			temp_n;
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
	temp_n = 1;
	locate_higher_2(blst, higher_pos, n, temp_n);
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
