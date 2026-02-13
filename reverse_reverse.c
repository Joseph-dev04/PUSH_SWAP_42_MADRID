/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:54:11 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/12 10:52:08 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **a)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	plast = *a;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*a = last;
	write (1, "rra\n", 4);
}

/* void	ft_rra(t_list **a)
{
	t_list	*prev;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return;

	prev = NULL;
	last = *a;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}

	prev->next = NULL;   // el penúltimo ahora es el último
	last->next = *a;     // el antiguo último apunta al primero
	*a = last;           // actualizamos head

	write(1, "rra\n", 4);
} */


void	ft_rrb(t_list **b)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	plast = *b;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*b = last;
	write (1, "rrb\n", 4);
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
	write (1, "rrr\n", 4);
}
