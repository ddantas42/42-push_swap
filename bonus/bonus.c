/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:19:16 by ddantas-          #+#    #+#             */
/*   Updated: 2023/02/12 16:24:53 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_stuff(t_bonus_list *lst, int *stack_a, int *stack_b, int error)
{
	if (error && error != 2 && error != 3)
		ft_printf("Error\n");
	if (error == 0 || error == 1)
		free(stack_b);
	if (stack_a)
		free(stack_a);
	if (lst)
		ft_freelist(lst, 0, 3);
	exit(EXIT_FAILURE);
}

int	ft_strlen(const char *str)
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
	char		str[4];
	int			len;
	
	rd = read(STDIN_FILENO, str, 1)
	while(rd > 0)
	{
		str[2] = '\0';
		ft_printf("%s\n");
		rd = read(STDIN_FILENO, str, 1)
	}
	return (0);
}

int main(int argc, char **argv)
{
	int				*stack_a;
	t_bonus_list	*alst;
	t_bonus_list	*blst;

	if (argc == 1)
		return (0);
	alst = 0;
	blst = 0;
	stack_a = (int *)malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		free_stuff(alst, stack_a, 0, 1);
	protection(&alst, stack_a, argc, argv);
	input_handler(&alst, &blst);
	ft_freelist(alst, blst, 0);
	return (0);
}