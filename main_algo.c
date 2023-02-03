/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/03 14:56:15 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



# include "push_swap.h"

int	get_lower_pos(t_ps_list *alst, t_ps_list *temp_min)
{
	t_ps_list	*temp;
	int			n;


	temp = alst;
	n = 0;
	while (temp)
	{
		if (temp->data == temp_min->data)
			break ;
		n++;
		temp = temp->next;
	}
	return (n);
}

void	search_lower(t_ps_list **alst, t_ps_list **blst)
{
	t_ps_list	*temp;
	t_ps_list	*temp_min;
	int			temp_min_int;
	int			n;

	temp = *alst;
	temp_min_int = temp->data;
	temp_min = temp;
	while (temp)
	{
		if (temp->data < temp_min_int)
		{
			temp_min = temp;
			temp_min_int = temp->data;
		}
		temp = temp->next;
	}
	n = get_lower_pos(*alst, temp_min);

	while (n--)
	{
		ra(alst, 0);
		is_it_sorted(alst, blst);
	}
	pb(blst, alst);
}


void	main_algorithm(t_ps_list *alst, t_ps_list *blst)
{
	int n = 0;
	while (1)
	{
		search_lower(&alst, &blst);
		is_it_sorted(&alst, &blst);
	}
}