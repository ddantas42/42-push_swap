/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:32:24 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/30 15:15:49 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_ps_list **alst, int rr)
{
	t_ps_list	*temp;
	
	if ((*alst) == NULL || (*alst)->next == NULL)
		return ;
	if (rr == 0)
		ft_printf("ra\n");

	temp = (*alst);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*alst);
	*alst = (*alst)->next;
	temp->next->next = NULL;
		
}