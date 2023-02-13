/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:46:27 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/13 18:34:21 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

char	set_zero(char str[])
{
	int	n;

	n = 0;
	str[n++] = '0';
	str[n++] = '0';
	str[n++] = '0';
	str[n++] = '0';
	str[n] = '\0';
	return (str);
}

int	select_arg(char str[])
{
	int n;

	n = 0;
	while (str[n] != '\n' || str[n] != '\0')
		n++;
	return (n);
}

int	input_handler(t_bonus_list **alst, t_bonus_list **blst)
{
	ssize_t		rd;
	char		str[5];
	
	set_zero(str);
	rd = read(STDIN_FILENO, str, 5);
	while(rd > 0)
	{
		ft_printf("str = %s\n", str);


		ft_printf("zero str = %s\n", str);

		ft_printf("waiting..\n\n");
		
		
		rd = read(STDIN_FILENO, str, 1);

	}
	ft_freelist(*alst, *blst, 0);
	return (0);
}