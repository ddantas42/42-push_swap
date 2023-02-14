/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:46:27 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/14 13:18:03 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	set_zero(char str[])
{
	int	n;

	n = 0;
	str[n++] = '\0';
	str[n++] = '\0';
	str[n] = '\0';
	return (*str);
}

int	select_arg(char str[])
{
	if (str[0] == 's' && str[1] == 'a' && str[2] == '\n')
		return (SA);
	else if (str[0] == 's' && str[1] == 'b' && str[2] == '\n')
		return (SB);
	else if (str[0] == 's' && str[1] == 's' && str[2] == '\n')
		return (SS);
	else if (str[0] == 'p' && str[1] == 'a' && str[2] == '\n')
		return (PA);
	else if (str[0] == 'p' && str[1] == 'b' && str[2] == '\n')
		return (PB);
	else if (str[0] == 'r' && str[1] == 'a' && str[2] == '\n')
		return (RA);
	else if (str[0] == 'r' && str[1] == 'b' && str[2] == '\n')
		return (RB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\n')
		return (RR);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] != '\n')
		return (READ_MORE);
	return (0);
}

int	arg_handler(int arg, char str[])
{
	char	c[1];

	c[0] = '\0';
	if (arg != READ_MORE)
		return(arg);
	if (arg == READ_MORE && read(STDIN_FILENO, c, 1) <= 0)
		return (0);
	else if (c[0] != '\n')
		return (0);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a' && c[0] == '\n')
		return (RRA);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b' && c[0] == '\n')
		return (RRB);
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r' && c[0] == '\n')
		return (RRR);
	return (0);
	
}

void	exec_arg(int arg, t_bonus_list **alst, t_bonus_list **blst)
{
	if (arg == SA)
		*alst = sa(*alst);
	else if (arg == SB)
		*blst = sb(*blst);
	else if (arg == SS)
		ss(*alst, *blst);
	else if (arg == PA)
		pa(blst, alst);
	else if (arg == PB)
		pb(blst, alst);
	else if (arg == RA)
		ra(alst);
	else if (arg == RB)
		rb(blst);
	else if (arg == RR)
		rr(alst, blst);
	else if (arg == RRA)
		rra(alst);
	else if (arg == RRB)
		rrb(blst);
	else if (arg == RRR)
		rrr(alst, blst);
}


int	input_handler(t_bonus_list **alst, t_bonus_list **blst)
{
	ssize_t		rd;
	char		str[3];
	int			arg;

	set_zero(str);
	rd = read(STDIN_FILENO, str, 3);
	while(rd > 0)
	{
		arg = select_arg(str);
		if (arg == 0)
			return(1);
		arg = arg_handler(arg, str);
		if (arg == 0)
			return (1);
		if (arg > 0 && arg < 12)
			exec_arg(arg, alst, blst);
		else
			return (1);
		set_zero(str);
		rd = read(STDIN_FILENO, str, 3);
	}
	return (0);
}
