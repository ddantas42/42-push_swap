/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_protection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:55:36 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/12 13:56:33 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	check_n(t_bonus_list **lst, char *str, int *stack_a, int *stack_b)
{
	int	n;

	n = 0;
	if (str)
	{
		while (str[n] == ' ' || str[n] == '\f' || str[n] == '\n'
			|| str[n] == '\r' || str[n] == '\t' || str[n] == '\v'
			|| str[n] == '+' || str[n] == '-')
			n++;
		while (str[n] != '\0')
		{
			if (str[n] < '0' || str[n] > '9')
				free_stuff(*lst, stack_a, stack_b, 1);
			n++;
		}
	}
	n = ft_atoi(str, lst, stack_a, stack_b);
	ft_add_alst(lst, 0, n);
	return (n);
}

int	duplicate_check(t_bonus_list *lst, int *stack_a, int *stack_b, int argc)
{
	int	l;
	int	n;

	l = 0;
	n = 0;
	while (n < argc - 1)
	{
		l = 0;
		while (l < argc - 1)
		{
			if (n == l)
			{
				l++;
				break ;
			}
			if (stack_a[n] == stack_b[l++])
				free_stuff(lst, stack_a, stack_b, 1);
		}
	n++;
	}
	free(stack_a);
	free(stack_b);
	return (0);
}

int	*protection(t_bonus_list **lst, int *stack_a, int argc, char **argv)
{
	int	n;
	int	*stack_b;

	stack_b = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_b || argc < 2)
		free_stuff(*lst, stack_a, stack_b, 1);
	n = 0;
	while (argv[n + 1])
	{
		stack_a[n] = check_n(lst, argv[n + 1], stack_a, stack_b);
		if (argv[n + 1][0] != '0' && stack_a[n] == 0)
			free_stuff(*lst, stack_a, stack_b, 1);
		stack_b[n] = stack_a[n];
		n++;
	}
	duplicate_check(*lst, stack_a, stack_b, argc);
	return (0);
}
