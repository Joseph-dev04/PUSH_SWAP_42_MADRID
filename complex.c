/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:03:06 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 19:06:19 by aitorres         ###   ########.fr       */
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

void	ft_order_bits(t_principal **principal, int size)
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

void	complex_extraction(t_principal **principal, int size)
{
	(*principal)->bench->compute_disorder = compute_disorder((*principal)->a);
	(*principal)->bench->complex = 1;
	ft_quicksort(&(*principal)->a);
	ft_order_bits(principal, size);
}
