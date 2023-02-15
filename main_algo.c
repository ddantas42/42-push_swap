/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/15 12:36:06 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*algorithm_3_pos(t_ps_list *alst, int lstsize)
{
	if (lstsize == 2 || (alst->pos > alst->next->pos
			&& alst->pos < alst->next->next->pos))
		sa(alst, 0);
	else if (alst->pos > alst->next->pos
		&& alst->next->pos < alst->next->next->pos)
		ra(&alst, 0);
	else if (alst->pos < alst->next->pos
		&& alst->pos < alst->next->next->pos)
	{
		rra(&alst, 0);
		sa(alst, 0);
	}
	else if (alst->pos < alst->next->pos
		&& alst->pos > alst->next->next->pos)
		rra(&alst, 0);
	else if (alst->pos > alst->next->pos
		&& alst->next->pos > alst->next->next->pos)
	{
		sa(alst, 0);
		rra(&alst, 0);
	}
	return (alst);
}

void	main_algorithm(t_ps_list *alst, t_ps_list *blst, int lstsize)
{
	int	divide;

	if (lstsize < 10)
		divide = 1;
	else if (lstsize < 100)
		divide = 10;
	else if (lstsize >= 100 && lstsize < 500)
		divide = lstsize / 15;
	else
		divide = lstsize / 24;
	pb_algo(&alst, &blst, divide, lstsize);
	if (divide == 1)
	{
		alst = algorithm_3_pos(alst, 3);
		while (blst != NULL)
			pa(&blst, &alst);
		return ;
	}
	pa_algo(&alst, &blst, lstsize);
	is_it_sorted(&alst, &blst);
}
