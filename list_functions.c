/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:33:54 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 16:01:44 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_freelist(t_alist* head)
{
	t_alist	*tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
	exit(EXIT_FAILURE);
}

/*t_alist	*ft_add_lst(t_alist *lst, int n, int atoi)
{
	t_alist *new;
	t_alist	*temp;

	ft_printf("n = %d | atoi = %d\n", n, atoi);

	temp = malloc(sizeof(*temp));
	if (!temp)
		ft_freelist(lst);
	if (lst)
		temp = lst;
	new = malloc(sizeof(*new));
	if (!new)
		ft_freelist(lst);
	while (n--)
		temp++;	
	temp->next = new;
	new->data = atoi;
	new->next = NULL;
	return (0);
}*/

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