/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comple_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:53:03 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 16:39:23 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_simple(t_list *node, t_principal **principal)
{
	while (node->cost_a > 0)
	{
		ft_ra(principal, 0);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		ft_rra(principal, 0);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		ft_rb(principal, 0);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		ft_rrb(principal, 0);
		node->cost_b++;
	}
}

void	execute_mode(t_list *node, t_principal **principal)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		ft_rr(principal);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		ft_rrr(principal);
		node->cost_a++;
		node->cost_b++;
	}
	execute_simple(node, principal);
	ft_pa(principal, 0);
}

void	calcule_cost(t_list *a, t_list *b)
{
	int	a_size;
	int	b_size;

	a_size = ft_size_lis(a);
	b_size = ft_size_lis(b);
	while (b)
	{
		if (b->pos <= b_size / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = b->pos - b_size;
		if (b->target_pos <= a_size / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = b->target_pos - a_size;
		b = b->next;
	}
}

void	fin_rotate(t_principal **principal)
{
	int	pos;
	int	size;

	update_position((*principal)->a);
	pos = get_int_min((*principal)->a);
	size = ft_size_lis((*principal)->a);
	if (pos <= size / 2)
	{
		while (pos--)
			ft_ra(principal, 0);
	}
	else
	{
		while (pos++ < size)
			ft_rra(principal, 0);
	}
}

t_list	*get_cheapest(t_list *b)
{
	t_list	*cheap;
	int		min_cost;
	int		current_cost;

	min_cost = get_total_cost(b);
	cheap = b;
	while (b)
	{
		current_cost = get_total_cost(b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheap = b;
		}
		b = b->next;
	}
	return (cheap);
}
