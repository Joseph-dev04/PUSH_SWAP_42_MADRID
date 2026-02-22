/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:03:06 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 13:50:36 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(int size)
{
	int	count_bits;

	count_bits = 0;
	while ((size >> count_bits) != 0)
		count_bits++;
	return (count_bits);
}

int	get_target_pos(t_list *a, int b_index)
{
	t_list	*tmp;
	int	target_index;
	int	target_pos;

	tmp = a;
	target_index = INT_MAX;
	target_pos = 0;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			
		}
	}
}

void	update_position(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

void	ft_orden_bits(t_principal **principal, int size)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	max = ft_max_bits(size - 1);
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if ((((*principal)->a->index >> i) & 1) == 1)
				ft_ra(principal, 0);
			else
				ft_pb(principal, 0);
			j++;
		}
		while ((*principal)->b)
		{
			ft_pa(principal, 0);
		}
		i++;
	}
}

void	ft_radix(t_principal **principal, int size)
{
	ft_quicksort(&(*principal)->a);
	ft_orden_bits(principal, size);
}
