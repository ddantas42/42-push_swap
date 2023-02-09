/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:58 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/09 14:02:39 by ddantas-         ###   ########.fr       */
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
	while (lstsize > 3)
	{
		if ((*alst)->pos >= min_pos && (*alst)->pos <= div)
		{
			//ft_printf("min %d => pos >= div %d\n", min_pos, div);
			if ((*alst)->pos == min_pos)
				min_pos++;
			pb(blst, alst);
			if (lstsize > 5)
				div++;
			lstsize--;
		}
		if ((*alst) == NULL)
			return ;
		if (lstsize <= 3)
			break ;
		locate_closer(alst, min_pos, div, lstsize);
		is_it_sorted(alst, blst);
	}
}
