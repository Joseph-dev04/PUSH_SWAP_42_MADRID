/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:19:36 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 18:41:54 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list *stack_a)
{
	long long		mistakes;
	long long		total_pairs;
	t_list			*n_nodo_a;
	t_list			*n_nodo_a_next;

	mistakes = 0;
	total_pairs = 0;
	n_nodo_a = stack_a;
	n_nodo_a_next = n_nodo_a;
	while (n_nodo_a != NULL)
	{
		n_nodo_a_next = n_nodo_a->next;
		while (n_nodo_a_next != NULL)
		{
			total_pairs++;
			if (n_nodo_a->value > n_nodo_a_next->value)
				mistakes++;
			n_nodo_a_next = n_nodo_a_next->next;
		}
		n_nodo_a = n_nodo_a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}

void	ft_adaptive(t_principal **principal)
{
	float	num;

	num = compute_disorder((*principal)->a);
	(*principal)->bench->adaptive = 1;
	(*principal)->bench->compute_disorder = num;
	if (num >= 0.5f)
	{
		(*principal)->bench->complex = 1;
		push_back(principal);
	}
	else if (num < 0.5f && num >= 0.2f)
	{
		(*principal)->bench->medium = 1;
		medium_extraccion(principal);
	}
	else
	{
		(*principal)->bench->simple = 1;
		simple_extraction(principal);
	}
}
