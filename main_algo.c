/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/09 13:54:45 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_list_a(t_ps_list *lst)
{
	t_ps_list *temp = lst;
	ft_printf("A\n");
	while (temp)
	{
		ft_printf("lst.data = %d\n",temp->data);
		temp = temp->next;
	}
	ft_printf("_\n\n");
}

void	main_algorithm(t_ps_list *alst, t_ps_list *blst, int lstsize)
{
	int	divide;

	if (lstsize < 10)
		divide = 2;
	else if (lstsize < 100)
		divide = 10;
	else if (lstsize >= 100 && lstsize < 500)
		divide = lstsize / 15;
	else
		divide = lstsize / 24;
	pb_algo(&alst, &blst, divide, lstsize);

	//ft_printf("lstsize = %d\n", lstsize);
	print_list_a(alst);
	exit(1);
	algorithm_3(alst, 4);
	pa_algo(&alst, &blst, lstsize);
	is_it_sorted(&alst, &blst);
}
