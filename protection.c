/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:23:01 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/26 21:33:50 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stuff(int *stack_a, int *stack_b, int error)
{
	if (error)
		ft_printf("Error\n");
	free(stack_a);
	free(stack_b);
	exit(EXIT_FAILURE);
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
	n = 0;
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

int	*protection(int *stack_a, int *stack_b, int argc, char **argv)
{
	int	n;

	if (argc < 2)
		free_stuff(stack_a, stack_b, 1);
	n = 0;
	while (argv[n + 1])
	{
		stack_a[n] = check_n(argv[n + 1], stack_a, stack_b);
		if (argv[n + 1][0] != '0' && stack_a[n] == 0)
			free_stuff(stack_a, stack_b, 1);
		stack_b[n] = stack_a[n];
		n++;
	}
	duplicate_check(stack_a, stack_b, n);
	return (0);
}
