/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:03:23 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 17:01:38 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	num_len(int nb)
{
	return (nb % 10);
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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
