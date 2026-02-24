/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:33:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 16:39:19 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_position(t_list *a, t_list *b)
{
	while (b)
	{
		b->target_pos = get_target_pos(a, b->index);
		b = b->next;
	}
}

int	get_total_cost(t_list *node)
{
	if ((node->cost_a >= 0 && node->cost_b >= 0)
		|| (node->cost_a < 0 && node->cost_b < 0))
		return (max(ft_abs(node->cost_a), ft_abs(node->cost_b)));
	else
		return (ft_abs(node->cost_a) + ft_abs(node->cost_b));
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

static void	sort_three_elements(t_principal **principal)
{
	int	first;
	int	second;
	int	third;

	first = (*principal)->a->index;
	second = (*principal)->a->next->index;
	third = (*principal)->a->next->next->index;
	if (first > second && second < third && first < third)
		ft_sa(principal, 0);
	else if (first > second && second > third)
	{
		ft_sa(principal, 0);
		ft_rra(principal, 0);
	}
	else if (first > second && second < third && first > third)
		ft_ra(principal, 0);
	else if (first < second && second > third && first < third)
	{
		ft_sa(principal, 0);
		ft_ra(principal, 0);
	}
	else if (first < second && second > third && first > third)
		ft_rra(principal, 0);
	/*if (first > second && second > third)
	{
		ft_ra(principal, 0);
		if ((*principal)->a->index > (*principal)->a->next->index)
			ft_sa(principal, 0);
	}
	else if (second > first && second > third)
	{
		ft_rra(principal, 0);
		if ((*principal)->a->index > (*principal)->a->next->index)
			ft_sa(principal, 0);
	}
	else if (first > second)
		ft_sa(principal, 0);*/
}
static void	simple_small(t_principal **principal)
{
	int	size;

	size = ft_size_lis((*principal)->a);
	if (size <= 1)
		return ;
	if (size == 2 && (*principal)->a->index > (*principal)->a->next->index)
		ft_sa(principal, 0);
	else if (size == 3)
		sort_three_elements(principal);
}
void	initial_push(t_principal **principal)
{
	int	size;

	size = ft_size_lis((*principal)->a);
	while (size > 3)
	{
		ft_pb(principal, 0);
		size--;
	}
	if (size <= 3)
	{
		simple_small(principal);
		return ;
	}
}

void	push_back(t_principal **principal)
{
	t_list	*cheap;

	(*principal)->bench->complex = 1;
	(*principal)->bench->compute_disorder = compute_disorder((*principal)->a);
	ft_quicksort(&(*principal)->a);
	if ((*principal)->bench->compute_disorder > 0.0f)
	{
		initial_push(principal);
		while ((*principal)->b)
		{
			update_position((*principal)->a);
			update_position((*principal)->b);
			set_target_position((*principal)->a, (*principal)->b);
			calcule_cost((*principal)->a, (*principal)->b);
			cheap = get_cheapest((*principal)->b);
			execute_mode(cheap, principal);
		}
		fin_rotate(principal);
	}
}
