/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/26 18:53:41 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n(char *str)
{
	int	n;
 
	ft_printf("str = %s ", str);

	n = 0;
	if (str)
	{
		while (str[n])
		{
			if (ft_isdigit((int)str[n]) == 0)
					exit(EXIT_FAILURE);
			n++;
		}
	}
	return (0);
}

int	*protection(int *stack_a, int *stack_b, int argc, char **argv)
{
	int n;

	if (argc < 2)
		exit(EXIT_FAILURE);
	n = 0;
	while (argv[n + 1])
	{
		check_n(argv[n + 1]);
		stack_a[n] = ft_atoi(argv[n + 1]);
		stack_b[n] = stack_a[n];
		ft_printf("args_int[%d] = %d\n", n, stack_a[n]);
		n++;
	}
	return (stack_a);
}

int main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	n;
	int	l;

	stack_a = (int *)malloc(argc * sizeof(int));
	stack_b = (int *)malloc(argc * sizeof(int));
	protection(stack_a, stack_b, argc, argv);

	// Print Stack elements
	ft_printf("Stack: A\n");
	n = 0;
	while (stack_a[n])
		ft_printf("%d\n", stack_a[n++]);
	ft_printf("_\n");
	// End printing elements
	n = 0;
	l = 0;
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
				exit(EXIT_FAILURE);		
			}
			l++;
		}
	n++;
	}
	return (0);
}