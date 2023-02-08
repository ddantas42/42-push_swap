/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:58 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/08 15:11:32 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
/*
void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int	min_pos;

	min_pos = 1;
	while ((*alst))
	{
		
	}
}
*/