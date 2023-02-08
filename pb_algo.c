/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:58 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/08 16:31:24 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Old pb algo
void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int			min_pos;

	min_pos = lstsize - div;
	while (*alst)
	{
		if ((*alst)->pos >= min_pos)
		{
			pb(blst, alst);
			min_pos--;
			if (min_pos == 0)
				break ;
			continue ;
		}
		ra(alst, 0);
	}
	while (div-- > 0)
		pb(blst, alst);	
}
*/

void	locate_closer(t_ps_list **alst, int min_pos, int div, int lstsize)
{
	int			n;
	t_ps_list	*temp;

	temp = *alst;
	n = 0;
	while (temp)
	{
		if (temp->pos >= min_pos && temp->pos <= div)
			break ;
		n++;
		temp = temp->next;
	}
	if (n > lstsize / 2)
	{
		while ((*alst)->pos < min_pos || (*alst)->pos > div)
			rra(alst, 0);
	}
	else
		while ((*alst)->pos < min_pos || (*alst)->pos > div)
			ra(alst, 0);
}

void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int	min_pos;

	min_pos = 1;
	while ((*alst))
	{
		if ((*alst)->pos >= min_pos && (*alst)->pos <= div)
		{
			if ((*alst)->pos == min_pos)
				min_pos++;
			pb(blst, alst);
			lstsize--;
			div++;
		}
		if ((*alst) == NULL)
			return ;
		locate_closer(alst, min_pos, div, lstsize);
	}
}
