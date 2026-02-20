/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:54:11 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 18:19:42 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_principal **principal)
{
	ft_rra(principal, 1);
	ft_rrb(principal, 1);
	write (1, "rrr\n", 4);
	if ((*principal)->bench)
	{
		(*principal)->bench->rrr_count++;
		(*principal)->bench->total_count++;
	}
}

void	ft_rra(t_principal **principal, int count_bench)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!principal || !*principal || !(*principal)->a || !(*principal)->a->next)
		return ;
	first = (*principal)->a;
	plast = (*principal)->a;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	(*principal)->a = last;
	write (1, "rra\n", 4);
	if (count_bench == 0)
	{
		(*principal)->bench->rra_count++;
		(*principal)->bench->total_count++;
		return ;
	}
}

void	ft_rrb(t_principal **principal, int count_bench)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!principal || !*principal || !(*principal)->b || !(*principal)->b->next)
		return ;
	first = (*principal)->b;
	plast = (*principal)->b;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	(*principal)->b = last;
	write (1, "rrb\n", 4);
	if (count_bench == 0)
	{
		(*principal)->bench->rrb_count++;
		(*principal)->bench->total_count++;
		return ;
	}
}
