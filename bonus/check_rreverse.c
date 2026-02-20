/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rreverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:37:20 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 10:53:19 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*b = last;
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
}

void    ft_check_rreverse(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "rra\n", ft_strlen2(line)))
        ft_rra(&(*bonus)->a);
    else if (ft_strnstr(line, "rrb\n", ft_strlen2(line)))
        ft_rrb(&(*bonus)->b);
    else if (ft_strnstr(line, "rrr\n", ft_strlen2(line)))
        ft_rrr(&(*bonus)->a, &(*bonus)->b);
}