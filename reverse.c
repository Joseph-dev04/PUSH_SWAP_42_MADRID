/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:51:33 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 13:49:00 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_principal **principal)
{
	ft_ra((principal), 1);
	ft_rb((principal), 1);
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
	write (1, "ra\n", 3);
	if (count_bech == 0)
	{
		(*principal)->bench->ra_count++;
		(*principal)->bench->total_count++;
		return ;
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
	write (1, "rb\n", 3);
	if (count_bech == 0)
	{
		(*principal)->bench->rb_count++;
		(*principal)->bench->total_count++;
		return ;
	}
}
