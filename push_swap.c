/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/10 14:31:41 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_ps_list **alst)
{
	t_ps_list	*temp;
	t_ps_list	*temp_2;

	temp = *alst;
	temp_2 = *alst;
	while (temp)
	{
		temp->pos = 1;
		temp_2 = *alst;
		while (temp_2)
		{
			if (temp->data > temp_2->data)
				temp->pos++;
			temp_2 = temp_2->next;
		}
		temp = temp->next;
	}
}

t_ps_list	*ss(t_ps_list *alst, t_ps_list *blst)
{
	alst = sa(alst, 1);
	blst = sb(blst, 1);
	ft_printf("ss\n");
	return (0);
}

void	rr(t_ps_list **alst, t_ps_list **blst)
{
	ra(alst, 1);
	rb(blst, 1);
	ft_printf("rr\n");
}

void	rrr(t_ps_list **alst, t_ps_list **blst)
{
	rra(alst, 1);
	rrb(blst, 1);
	ft_printf("rrr\n");
}

int	main(int argc, char **argv)
{
	int			*stack_a;
	t_ps_list	*alst;
	t_ps_list	*blst;

	if (argc == 1)
		return (0);
	alst = 0;
	blst = 0;
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);
	protection(&alst, stack_a, argc, argv);
	is_it_sorted(&alst, &blst);
	get_pos(&alst);
	if (argc <= 4)
		algorithm_3(alst, argc);
	else if (argc > 4)
		main_algorithm(alst, blst, argc - 1);
	ft_freelist(alst, blst, 0);
	return (0);
}
