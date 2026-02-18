/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:34:37 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/18 17:31:04 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// extern int contador;
void	ft_ss(t_principal **principal)
{
	if (!principal || !*principal)
		return ;
	ft_sa((principal), 1);
	ft_sb((principal), 1);
	// contador++;
	write(1, "ss\n", 3);
	if ((*principal)->bench)
		{
			(*principal)->bench->ss_count++;
			(*principal)->bench->total_count++;
		}
}

void	ft_sa(t_principal **principal, int count_bech)
{
	t_list	*first;
	t_list	*second;

	// if (!(*principal)->a || !(*principal)->a->next)
	// 	return ;
	if (!principal || !*principal || !(*principal)->a || !(*principal)->a->next)
		return ;
	first = (*principal)->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*principal)->a = second;
	// contador++;
	write(1, "sa\n", 3);
	if (count_bech == 0)
	{
		(*principal)->bench->sa_count++;
		(*principal)->bench->total_count++;
		return ;
	}
}

void	ft_sb(t_principal **principal, int count_bech)
{
	t_list	*first;
	t_list	*second;

	// if (!(*principal)->b || !(*principal)->b->next)
	//     return ;
	if (!principal || !*principal || !(*principal)->b || !(*principal)->b->next)
		return ;
	first = (*principal)->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	(*principal)->b = second;
	// contador++;
	write(1, "sb\n", 3);
	if (count_bech == 0)
	{
		if ((*principal)->bench)
		{
			(*principal)->bench->sb_count++;
			(*principal)->bench->total_count++;
		}
	}
}
