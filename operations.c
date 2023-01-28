/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/2 7 09:40:42 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 16:49:36 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


t_alist	*sa(t_alist	*alst, int ss)
{
	int		n_temp;
	
	if (ss == 0)
		ft_printf("sa\n");
	if (alst != NULL && alst->next != NULL)
	{
		n_temp = alst->next->data;
		alst->next->data = alst->data;
		alst->data = n_temp;
	}
	return (alst);
}

t_blist	*sb(t_blist *blst, int ss)
{
	int		n_temp;

	if (ss == 0)
		ft_printf("sb\n");
	if (blst != NULL && blst->next != NULL)
	{
		n_temp = blst->next->data;
		blst->next->data = blst->data;
		blst->data = n_temp;
	}
	return (blst);
}

t_alist	*ss(t_alist *alst, t_blist *blst)
{
	alst = sa(alst, 1);
	blst = sb(blst, 1);
	ft_printf("ss\n");
	return (0);
}
/*
t_alist	*pa(t_alist *alst, t_blist *blst)
{
	t_blist	*temp;
	
	if (blst == NULL)
		return (alst);
	alst = ft_add_alst(alst, blst, alst->data);
	temp = blst;
    blst = blst->next;
	free(temp);
	ft_printf("pa\n");
	return (alst);
}
*/
void	pb(t_blist **blst, t_alist **alst, int data, int argc)
{
	t_blist	*new;
	
	ft_printf("argc = %d\n", argc);
	ft_printf("b list size = %d\n", ft_lstsize_2(0, (*blst)));
	new = (t_blist *)malloc(sizeof(t_blist));
	if (!new)
	{
		free(new);
		ft_freelist((*alst), (*blst), 2);
	}
	new->data = data;
	new->next = (*blst);
	(*blst) = new;
	pop_top_a(alst);
	ft_printf("pb\n");
}
