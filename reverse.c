/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:51:33 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/12 09:51:41 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a);
	ft_rb(b);
	write (1, "rr\n", 3);
}

void	ft_rb(t_list **b)
{
	t_list	*first;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	ft_add_back(b, first);
	write (1, "rb\n", 3);
}

void	ft_ra(t_list **a)
{
	t_list	*first;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	ft_add_back(a, first);
	write (1, "ra\n", 3);
}
