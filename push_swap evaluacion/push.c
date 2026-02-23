/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:53:33 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 18:23:52 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_principal **principal, int count_bench)
{
	t_list	*temp;

	if (!principal || !*principal || !(*principal)->b)
		return ;
	temp = (*principal)->b;
	(*principal)->b = (*principal)->b->next;
	temp->next = (*principal)->a;
	(*principal)->a = temp;
	if ((*principal)->bench->count_only == 0)	// evaluacion
		write (1, "pa\n", 3);
	if (count_bench == 0 && (*principal)->bench)
	{
		(*principal)->bench->pa_count++;
		(*principal)->bench->total_count++;
	}
}

void	ft_pb(t_principal **principal, int count_bench)
{
	t_list	*temp;

	if (!principal || !*principal || !(*principal)->a)
		return ;
	temp = (*principal)->a;
	(*principal)->a = (*principal)->a->next;
	temp->next = (*principal)->b;
	(*principal)->b = temp;
	if ((*principal)->bench->count_only == 0) // evaluacion
		write (1, "pb\n", 3);
	if (count_bench == 0 && (*principal)->bench)
	{
		(*principal)->bench->pb_count++;
		(*principal)->bench->total_count++;
	}
}
