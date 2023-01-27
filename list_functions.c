/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:33:54 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 19:24:34 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alist *create_list(t_alist *lst, int *stack, int argc)
{
	int		n;
	t_alist	*temp;

	temp = lst;
	n = 0;
	while (n < argc - 1)
	{
		if (n == 0)
		{
			ft_add_lst(lst, stack[n++], 1);
		}
		else	
		{
			ft_printf("stack[%d] = %d \n", n, stack[n]);
			ft_add_lst(temp, stack[n++], 0);
		}		
		temp = temp->next;
	}
	return (lst);
}

void ft_freelist(t_alist* lst)
{
	t_alist	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		printf("free temp = %d\n", temp);
		free(temp);
	}
	exit(EXIT_FAILURE);
}

t_alist	*ft_add_lst(t_alist *lst, int atoi, int p)
{
	t_alist *new;
	t_alist	*temp;

	if (p)
	{
		lst->data = atoi;
		lst->next = NULL;
		return (lst);
	}
	temp = lst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;	
	new = (t_alist *)malloc(sizeof(new));
	if (!new)
	{
		free(new);	
		ft_freelist(lst);
	}
	new->data = atoi;
	new->next = NULL;
	if (temp != NULL)
		temp->next = new;
	else
		lst = new;
	return (lst);
}

int	ft_lstsize_2(t_alist *lst)
{
	int	n;

	n = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}