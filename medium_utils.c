/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:11:24 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/25 12:44:00 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_index(t_list **a)
{
	t_list	*nodo_a;

	nodo_a = *a;
	while (nodo_a)
	{
		nodo_a->index = -1;
		nodo_a = nodo_a->next;
	}
}

static int	should_rotate_a(t_principal *principal, int min_val)
{
	int	size;
	int	next_val;
	int	next_next_val;

	size = ft_size_lis(principal->a);
	if (size != 5)
		return (0);
	next_val = principal->a->next->value;
	next_next_val = principal->a->next->next->value;
	if (next_val == min_val || next_next_val == min_val)
		return (1);
	return (0);
}

void	sort_five_elements(t_principal **principal)
{
	int		min_val;
	t_list	*tmp;

	while (ft_size_lis((*principal)->a) > 3)
	{
		min_val = (*principal)->a->value;
		tmp = (*principal)->a;
		while (tmp)
		{
			if (tmp->value < min_val)
				min_val = tmp->value;
			tmp = tmp->next;
		}
		while ((*principal)->a->value != min_val)
		{
			if (should_rotate_a(*principal, min_val))
				ft_ra(principal, 0);
			else
				ft_rra(principal, 0);
		}
		ft_pb(principal, 0);
	}
	sort_three_elements(principal);
	while ((*principal)->b)
		ft_pa(principal, 0);
}
