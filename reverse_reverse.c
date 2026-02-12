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
	while (plast->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*a = last;
	write (1, "rra\n", 4);
}

void	ft_rrb(t_list **b)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	plast = *b;
	while (plast->next)
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
