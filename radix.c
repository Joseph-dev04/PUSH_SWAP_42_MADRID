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

int	ft_max_bits(int size)
{
	int	count_bits;

	count_bits = 0;
	while ((size >> count_bits) != 0)
		count_bits++;
	return (count_bits);
}

void	ft_orden_bits(t_list **a, t_list **b, int size)
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
			if ((((*a)->index >> i)& 1) == 1)
				ft_ra(a);
			else
				ft_pb(a, b);
			j++;
		}
		while ((*b))
		{
			ft_pa(a, b);
		}
		i++;
	}
}

void	ft_radix(t_list **a, t_list **b, int size)
{
	ft_quicksort(a, b);
	ft_orden_bits(a, b, size);
}
