/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:23:01 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/27 12:29:25 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stuff(int *stack_a, int *stack_b, int error)
{
	if (error && error != 2)
		ft_printf("Error\n");
	if (error == 0 || error == 1)
		free(stack_b);
	free(stack_a);
	exit(EXIT_FAILURE);
}

int	already_sorted(int *stack_a, int *stack_b, int argc, int n)
{
	while (n < argc - 2)
	{
		if (stack_a[n] < stack_a[n + 1])
		{
			n++;
			continue ;
		}
		else
		{
			free(stack_b);
			return (0);
		}
	}
	free_stuff(stack_a, stack_b, 0);
	return (1);
}

int	check_n(char *str, int *stack_a, int *stack_b)
{
	int	n;

	n = 0;
	if (str)
	{
		while (str[n] == ' ' || str[n] == '\f' || str[n] == '\n'
			|| str[n] == '\r' || str[n] == '\t' || str[n] == '\v'
			|| str[n] == '+' || str[n] == '-')
			n++;
		while (str[n])
		{
			if (ft_isdigit((int)str[n]) == 0)
				free_stuff(stack_a, stack_b, 1);
			n++;
		}
	}
	return (ft_atoi(str));
}

void	duplicate_check(int *stack_a, int *stack_b, int n)
{
	int	l;

	l = 0;
	while (stack_a[n])
	{
		l = 0;
		while (stack_b[l])
		{
			if (n == l)
			{
				l++;
				break ;
			}
			if (stack_a[n] == stack_b[l++])
				free_stuff(stack_a, stack_b, 1);
		}
	n++;
	}
}

int	*protection(int *stack_a, int argc, char **argv)
{
	int	n;
	int	*stack_b;

	stack_b = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_b || argc < 2)
		free_stuff(stack_a, stack_b, 1);
	n = 0;
	while (argv[n + 1])
	{
		stack_a[n] = check_n(argv[n + 1], stack_a, stack_b);
		if (stack_a[n] > 2147483646 || stack_b[n] < -2147483647)
			free_stuff(stack_a, stack_b, 1);
		if (argv[n + 1][0] != '0' && stack_a[n] == 0)
			free_stuff(stack_a, stack_b, 1);
		stack_b[n] = stack_a[n];
		n++;
	}
	n = 0;
	duplicate_check(stack_a, stack_b, n);
	already_sorted(stack_a, stack_b, argc, n);
	return (0);
}
