/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:40 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/07 15:28:34 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	main_algorithm(t_ps_list *alst, t_ps_list *blst, int lstsize)
{
	int	divide;

	if (lstsize < 100)
		divide = 4;
	else if (lstsize >= 100 && lstsize < 500)
		divide = lstsize;
	else
		divide = lstsize / 20;
	pb_algo(&alst, &blst, divide, lstsize);
	ft_printf("All in B :D\n");
	is_it_sorted(&alst, &blst);
}