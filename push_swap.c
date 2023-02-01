/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/01 16:56:38 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_ps_list **lst, int *stack_a, int *stack_b)
{
	int	n;
	int	s;
	int	c;

	c = 0;
	s = 1;
	n = 0;
	while (str[n] == ' ' || str[n] == '\f' || str[n] == '\n'
		|| str[n] == '\r' || str[n] == '\t' || str[n] == '\v')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			s *= -1;
		n++;
	}
	while (str[n])
	{
		if (str[n] >= 48 && str[n] <= 57)
			c = (c * 10) + (str[n] - 48);
		else
			break ;
		n++;
	}
	if (c > 2147483647 || (c * s) < -2147483648)
		free_stuff(*lst, stack_a, stack_b, 1);
	return (c * s);
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

	alst = 0;
	blst = 0;
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);
	protection(&alst, stack_a, argc, argv);
	if (argc < 11)
		algorithm(alst, blst);
	if (argc > 10)
		ft_printf("NOT YET DEVELOPED :(\n");
	ft_freelist(alst, blst, 0);
	return (0);
}
