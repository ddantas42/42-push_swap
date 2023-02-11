/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:45:58 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/11 15:05:50 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Old pb algo
void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int			min_pos;

	min_pos = lstsize - div;
	while (*alst)
	{
		if ((*alst)->pos >= min_pos)
		{
			pb(blst, alst);
			min_pos--;
			if (min_pos == 0)
				break ;
			continue ;
		}
		ra(alst, 0);
	}
	while (div-- > 0)
		pb(blst, alst);	
}
Old pb algo End */

// Fast one
int	locate_closer_below(t_ps_list **alst, int min_pos, int div)
{
	t_ps_list	*temp;
	int			n;

	n = 0;
	temp = *alst;
	while (temp)
	{
		if (temp->pos >= min_pos && temp->pos <= div)
			n = 0;
		n++;
		temp = temp->next;
	}
	return (n);
}

void	locate_closer(t_ps_list **alst, int min_pos, int div, int lstsize)
{
	int			n;
	t_ps_list	*temp;

	temp = *alst;
	n = 0;
	while (temp)
	{
		if (temp->pos >= min_pos && temp->pos <= div)
			break ;
		n++;
		temp = temp->next;
	}
	if (n > lstsize / 2)
	{
		while ((*alst)->pos < min_pos || (*alst)->pos > div)
			rra(alst, 0);
	}
	else
		while ((*alst)->pos < min_pos || (*alst)->pos > div)
			ra(alst, 0);
}

//	Fast one
void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int	min_pos;

	min_pos = 1;
	while (lstsize)
	{
		if ((*alst)->pos >= min_pos && (*alst)->pos <= div)
		{
			if ((*alst)->pos == min_pos)
				min_pos++;
			pb(blst, alst);
			lstsize--;
			div++;
		}
		if (lstsize <= 3 && div <= 10)
			return ;
		if ((*alst) == NULL)
			return ;
		locate_closer(alst, min_pos, div, lstsize);
		is_it_sorted(alst, blst);
	}
}  /*Fast one End  */

/*
void passa_metade(t_ps_list **alst, t_ps_list **blst, int menor, int maior)
{
	int media;
	int mandar;
	int counter;
	static int n = 0;
	if (menor >= maior)
	{
		ra(alst, 0);
		return ;
	}
	media = (maior + menor) / 2;
	mandar = (maior - menor) / 2;
	if (((maior - menor)) % 2 != 0)
		mandar++;
	counter = 0;
	while (mandar > 0)
	{
		if ((*alst)->pos >= menor && (*alst)->pos <= media)
		{
			pb(blst, alst);
			mandar--;
		}
		else 
		{
			counter++;
			ra(alst, 0);
		}
	}
	while (--counter > 0 && n)
		rra(alst, 0);
	n = 1;
	while (*blst)
		pa(blst, alst);
	passa_metade(alst, blst, menor, media);
	passa_metade(alst, blst, media + 1, maior);
	if (menor < maior)
	{
		media = (maior + menor) / 2;
		mandar = (maior - menor) / 2;
		if (((maior - menor)) % 2 != 0)
			mandar++;
		counter = 0;
		while (mandar > 0)
		{
			if ((*alst)->pos >= menor && (*alst)->pos <= media)
			{
				pb(blst, alst);
				mandar--;
			}
			else 
			{
				counter++;
				ra(alst, 0);
			}
		}	
		while (--counter > 0 && n)
			rra(alst, 0);
		n = 1;
		while (*blst)
			pa(blst, alst);
		passa_metade(alst, blst, menor, media);
		passa_metade(alst, blst, media + 1, maior);
	}
	else
		ra(alst, 0);
}

void	pb_algo(t_ps_list **alst, t_ps_list **blst, int div, int lstsize)
{
	int	new_lst;
	int	min;

	new_lst = lstsize;
	min = 1;
	while (min <= new_lst)
	{
		lstsize = new_lst;
		while (lstsize > 1)
		{
			passa_metade(alst, blst, min, lstsize);
			lstsize /= 2;
		}
		ra(alst, 0);
		ra(alst, 0);
		min += 2;
	}*/
	/*
	(void)div;
	passa_metade(alst, blst, 1, lstsize);
	//pb_algo_2(alst, blst, div, lstsize);*/
//}*/
