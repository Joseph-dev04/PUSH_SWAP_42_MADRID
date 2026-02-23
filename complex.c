/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:33:47 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 13:34:17 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	get_target_pos(t_list *a, int b_index);

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_int_min(t_list *stack)
{
	int	min_index;
	int	min_pos;

	min_index = stack->index;
	min_pos = stack->pos;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = stack->pos;
		}
		stack = stack->next;
	}
	return (min_pos);
}

void	set_target_position(t_list *a, t_list *b)
{
	while (b)
	{
		b->target_pos = get_target_pos(a, b->index);
		b = b->next;
	}
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

int	get_target_pos(t_list *a, int b_index)
{
	t_list	*tmp;
	int		target_index;
	int		target_pos;

	tmp = a;
	target_index = INT_MAX;
	target_pos = 0;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	return (get_int_min(a));
}

int	ft_abs(int	num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	get_total_cost(t_list *node)
{
	if ((node->cost_a >= 0 && node->cost_b >= 0)
		|| (node->cost_a < 0 && node->cost_b < 0))
		return (max(ft_abs(node->cost_a), ft_abs(node->cost_b)));
	else
		return (ft_abs(node->cost_a) + ft_abs(node->cost_b));
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
	ft_pa(principal, 0);
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


void	final_rotate(t_principal **principal)
{
	int	pos;
	int	size;

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
		simple_small_extraction(principal);
		return ;
	}
}

void	push_back(t_principal **principal)
{
	t_list	*cheap;
	(*principal)->bench->complex = 1;
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
	final_rotate(principal);
}
