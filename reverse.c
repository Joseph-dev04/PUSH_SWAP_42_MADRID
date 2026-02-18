/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:51:33 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/18 18:07:02 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// extern int contador;
void	ft_rr(t_principal **principal)
{
	ft_ra((principal), 1);
	ft_rb((principal), 1);
	// contador++;
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
	// (*principal)->a = (*principal)->a->next;
	(*principal)->a = first->next;
	first->next = NULL;
	ft_add_back(&(*principal)->a, first);
	// contador++;
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
	// (*principal)->b = (*principal)->b->next;
	(*principal)->b = first->next;
	first->next = NULL;
	ft_add_back(&(*principal)->b, first);
	// contador++;
	write (1, "rb\n", 3);
	if (count_bech == 0)
	{
		(*principal)->bench->rb_count++;
		(*principal)->bench->total_count++;
		return ;
	}
}




// void	ft_rr(t_list **a, t_list **b)
// {
// 	ft_ra(a);
// 	ft_rb(b);
// 	// contador++;
// 	write (1, "rr\n", 3);
// }



// void	ft_rb(t_list **b)
// {
// 	t_list	*first;

// 	if (!*b || !(*b)->next)
// 		return ;
// 	first = *b;
// 	*b = (*b)->next;
// 	first->next = NULL;
// 	ft_add_back(b, first);
// 	// contador++;
// 	write (1, "rb\n", 3);
// }




// void	ft_ra(t_list **a)
// {
// 	t_list	*first;

// 	if (!*a || !(*a)->next)
// 		return ;
// 	first = *a;
// 	*a = (*a)->next;
// 	first->next = NULL;
// 	ft_add_back(a, first);
// 	// contador++;
// 	write (1, "ra\n", 3);
// }
