/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:03:06 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/13 10:11:18 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
void	ft_orden(t_list **b)
{
	t_list	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	while (first && first->next)
	{
		if ((first->value % 10) > (first->next->value % 10))
		{
			ft_sb(b);
			first = (*b)->next;
		}
		else
			break ;
	}
}*/

void	ft_unit(t_list **a, t_list **b)
{
	while (*a)
	{
		if (*b)
		{
			ft_pb (a, b);
			ft_orden(b);
		}
		else
			ft_pb(a, b);
		//*a = (*a)->next;
		//printf("unit :%i\n", (*a)->value);
	}
}

void	ft_radix(t_list **a, t_list **b)
{
	int	*list_num;

	list_num = ft_quicksort(list_num, a);
	ft_unit(a, b);
}
