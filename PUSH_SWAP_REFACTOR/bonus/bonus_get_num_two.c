/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_num_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:13:09 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/23 17:13:46 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

float	compute_disorder(t_list *stack_a)
{
	long long		mistakes;
	long long		total_pairs;
	t_list			*n_nodo_a;
	t_list			*n_nodo_b;

	mistakes = 0;
	total_pairs = 0;
	n_nodo_a = stack_a;
	n_nodo_b = n_nodo_a;
	while (n_nodo_a != NULL)
	{
		n_nodo_b = n_nodo_a->next;
		while (n_nodo_b != NULL)
		{
			total_pairs++;
			if (n_nodo_a->value > n_nodo_b->value)
				mistakes++;
			n_nodo_b = n_nodo_b->next;
		}
		n_nodo_a = n_nodo_a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	printf("%f", ((float)mistakes / (float)total_pairs));
	return ((float)mistakes / (float)total_pairs);
}
