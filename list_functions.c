/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:33:54 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/28 09:20:16 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alist	*pop_top(t_alist* lst)
{
  
    if (lst == NULL)
        return NULL;
    t_alist* temp = lst;
    lst = lst->next;
  
    free(temp);
  
    return (lst);
}

void ft_freelist(t_alist* lst)
{
	t_alist	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		printf("free temp = %p\n", temp);
		free(temp);
	}
	lst = NULL;
	exit(EXIT_FAILURE);
}

t_alist	*ft_add_lst(t_alist *lst, int atoi)
{
	t_alist *new;
	t_alist	*temp;

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