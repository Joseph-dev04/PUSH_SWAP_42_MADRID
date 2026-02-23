/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:51:33 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 18:32:02 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_principal **principal)
{
	ft_ra((principal), 1);
	ft_rb((principal), 1);
	if ((*principal)->bench->count_only == 0) // evaluacion
		write (1, "rr\n", 3);
	if ((*principal)->bench)
	{
		(*principal)->bench->rr_count++;
		(*principal)->bench->total_count++;
	}
}

void	ft_ra(t_principal **principal, int count_bech)
{
	t_list	*first;

	if (!*principal || !(*principal)->a || !(*principal)->a->next)
		return ;
	first = (*principal)->a;
	(*principal)->a = first->next;
	first->next = NULL;
	ft_add_back(&(*principal)->a, first);
	if (count_bech == 0)
	{
		if ((*principal)->bench->count_only == 0) // evaluacion
			write (1, "ra\n", 3);
		(*principal)->bench->ra_count++;
		(*principal)->bench->total_count++;
	}
}

void	ft_rb(t_principal **principal, int count_bech)
{
	t_list	*first;

	if (!principal || !*principal || !(*principal)->b || !(*principal)->b->next)
		return ;
	first = (*principal)->b;
	(*principal)->b = first->next;
	first->next = NULL;
	ft_add_back(&(*principal)->b, first);
	if (count_bech == 0)
	{
		if ((*principal)->bench->count_only == 0) // evaluacion
			write (1, "rb\n", 3);
		(*principal)->bench->rb_count++;
		(*principal)->bench->total_count++;
	}
}
