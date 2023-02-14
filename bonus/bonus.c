/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:19:16 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:51:04 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_stuff(t_bonus_list *lst, int *stack_a, int *stack_b, int error)
{
	if (error && error != 2 && error != 3)
		write(STDERR_FILENO, "Error\n", 6);
	if (error == 0 || error == 1)
		free(stack_b);
	if (stack_a)
		free(stack_a);
	if (lst)
		ft_freelist(lst, 0, 3);
	exit(EXIT_FAILURE);
}

void	rrr(t_bonus_list **alst, t_bonus_list **blst)
{
	rra(alst);
	rrb(blst);
}

void	is_it_sorted(t_bonus_list **alst, t_bonus_list **blst)
{
	t_bonus_list	*temp;

	if (*blst != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	temp = (*alst);
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break ;
		if (temp->data > temp->next->data)
		{
			ft_printf("KO\n");
			return ;
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	int				*stack_a;
	t_bonus_list	*alst;
	t_bonus_list	*blst;

	if (argc == 1)
		return (0);
	alst = 0;
	blst = 0;
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);
	protection(&alst, stack_a, argc, argv);
	if (input_handler(&alst, &blst))
	{
		ft_printf("KO\n");
		ft_freelist(alst, blst, 3);
	}
	is_it_sorted(&alst, &blst);
	ft_freelist(alst, blst, 0);
	return (0);
}
