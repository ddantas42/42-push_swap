/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:05:12 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:54:18 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_while_1(const char *str)
{
	int	n;

	n = 0;
	while (str[n] == ' ' || str[n] == '\f' || str[n] == '\n'
		|| str[n] == '\r' || str[n] == '\t' || str[n] == '\v')
		n++;
	return (n);
}

int	ft_atoi_if(const char *str, int *n)
{
	int	temp_n;

	temp_n = *n;
	if ((str[temp_n] == '-' || str[temp_n] == '+'))
	{
		*n = ++temp_n;
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str, t_ps_list **lst, int *stack_a, int *stack_b)
{
	int					n;
	int					s;
	unsigned long int	c;

	c = 0;
	n = ft_atoi_while_1(str);
	s = ft_atoi_if(str, &n);
	while (str[n])
	{
		if (str[n] >= 48 && str[n] <= 57
			&& ((c * 10) + (str[n] - 48)) > INT_MAX)
		{
			if (s == -1 && ((c * 10) + (str[n] - 48)) == (long) INT_MAX + 1
				&& str[n + 1] == '\0')
				break ;
			free_stuff(*lst, stack_a, stack_b, 1);
		}
		else if (str[n] >= 48 && str[n] <= 57)
			c = (c * 10) + (str[n] - 48);
		else
			break ;
		n++;
	}
	return (c * s);
}
