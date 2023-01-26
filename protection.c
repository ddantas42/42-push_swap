/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:23:01 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/26 19:39:55 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stuff(int *stack_a, int *stack_b)
{
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
					free_stuff(stack_a, stack_b);
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
				break;
			}
			if (stack_a[n] == stack_b[l])
			{
				ft_printf("Duplicated number detected!!\n");
				free_stuff(stack_a, stack_b);		
			}
			l++;
		}
	n++;
	}
}

int	*protection(int *stack_a, int *stack_b, int argc, char **argv)
{
	int n;

	if (argc < 2)
		free_stuff(stack_a, stack_b);
	n = 0;
	while (argv[n + 1])
	{
		stack_a[n] = check_n(argv[n + 1], stack_a, stack_b);
		if (argv[n + 1] != (char)'0' && stack_a[n] == 0)
			free_stuff(stack_a, stack_b);
		stack_b[n] = stack_a[n];
		n++;
	}
	duplicate_check(stack_a, stack_b, n);
	return (0);
}
