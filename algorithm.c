/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:22:56 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/15 13:01:09 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	*algorithm_3(t_ps_list *alst, int argc)
{
	if (argc == 3 || (alst->data > alst->next->data
			&& alst->data < alst->next->next->data))
		sa(alst, 0);
	else if (alst->data > alst->next->data
		&& alst->next->data < alst->next->next->data)
		ra(&alst, 0);
	else if (alst->data < alst->next->data
		&& alst->data < alst->next->next->data)
	{
		rra(&alst, 0);
		sa(alst, 0);
	}
	else if (alst->data < alst->next->data
		&& alst->data > alst->next->next->data)
		rra(&alst, 0);
	else if (alst->data > alst->next->data
		&& alst->next->data > alst->next->next->data)
	{
		sa(alst, 0);
		rra(&alst, 0);
	}
	return (alst);
}
