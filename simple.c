/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:20:13 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/20 19:10:56 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_elements(t_principal **principal)
{
	int	first;
	int	second;
	int	third;

	first = (*principal)->a->value;
	second = (*principal)->a->next->value;
	third = (*principal)->a->next->next->value;
	if (first > second && second > third)
	{
		ft_ra(principal, 0);
		if ((*principal)->a->value > (*principal)->a->next->value)
			ft_sa(principal, 0);
	}
	else if (second > first && second > third)
	{
		ft_rra(principal, 0);
		if ((*principal)->a->value > (*principal)->a->next->value)
			ft_sa(principal, 0);
	}
	else if (first > second)
		ft_sa(principal, 0);
}

void simple_small_extraction(t_principal **principal)
{
	int	size;

	size = ft_size_lis((*principal)->a);
	if (size <= 1)
		return ;
	if (size == 2 && (*principal)->a->value > (*principal)->a->next->value)
		ft_sa(principal, 0);
	else if (size == 3)
		sort_three_elements(principal);
}

static int	get_min_pos(t_list *stack)
{
	t_list	*min_node;
	int		min_pos;
	int		current_pos;

	min_node = stack;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->value < min_node->value)
		{
			min_node = stack;
			min_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	simple_large_extraction(t_principal **principal)
{
	int	min_pos;
	int	size;

	while ((*principal)->a)
	{
		min_pos = get_min_pos((*principal)->a);
		size = ft_size_lis((*principal)->a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ft_ra(principal, 0);
		}
		else
		{
			while (min_pos++ < size)
				ft_rra(principal, 0);
		}
		ft_pb(principal, 0);
	}
	while ((*principal)->b)
		ft_pa(principal, 0);
}

void	simple_extraction(t_principal **principal)
{
	int	size;

	(*principal)->bench->simple = 1;
	size = ft_size_lis((*principal)->a);
	(*principal)->bench->compute_disorder = compute_disorder((*principal)->a);
	if (size <= 3)
		simple_small_extraction(principal);
	else
		simple_large_extraction(principal);
}
