/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:58 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/07 15:46:14 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	get_lower_pos(t_ps_list *alst)
{
	int min;
	t_ps_list *temp;

	min = INT_MAX;
	temp = alst;
	while (temp)
	{
		if (temp->pos < min)
			min = temp->pos;
		temp = temp->next;
	}
	return (min);
}

int	get_lower_mov(t_ps_list *alst, int div)
{
	t_ps_list *temp;
	int min;
	int n;
	
	n = 0;
	min = get_lower_pos(alst);
	temp = alst;
	while (temp)
		temp = temp->next;
	return (n);
}*/

void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	t_ps_list	*temp;
	int			pos;
	int			min_pos;

	min_pos = lstsize - div;
	temp = *alst;
	while (temp)
	{
		if (temp->pos >= min_pos)
		{
			pb(blst, alst);
			min_pos--;
			if (min_pos == 0)
				break ;
			temp = *alst;
			continue ;
		}
		ra(alst, 0);
		temp = *alst;
	}
	while (div-- > 0)
		pb(blst, alst);	
}
