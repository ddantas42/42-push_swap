/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:47:35 by ddantas-          #+#    #+#             */
/*   Updated: 2023/01/23 21:16:37 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n(char *str)
{
	int	n;
 
	ft_printf("str = %s\n", str);

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

int	*protection(int *args_int, int argc, char **argv)
{
	int n;

	if (argc < 2)
		exit(EXIT_FAILURE);
	n = 0;
	while (argv[n + 1])
	{
		check_n(argv[n + 1]);
		args_int[n] = ft_atoi(argv[n + 1]);
		ft_printf("args_int[%d] = %d\n", n, args_int[n]);
		n++;
	}
	return (args_int);
}

int main(int argc, char **argv)
{
	int	*args_int;
	int	n;
	
	args_int = (int *)malloc(argc * sizeof(int));
	args_int = protection(args_int, argc, argv);
	ft_printf("arguments: \n");

	n = 0;
	while (args_int[n])
	{
		ft_printf("%d ", args_int[n]);
		n++;
	}
	ft_printf("\n", args_int[n]);
	return (0);
}