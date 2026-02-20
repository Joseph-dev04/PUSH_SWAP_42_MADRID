/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:37:37 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 11:02:21 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	ft_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

static void	ft_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void    ft_check_push(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "pa\n", ft_strlen2(line)))
        ft_pa(&(*bonus)->a, &(*bonus)->b);
    else if (ft_strnstr(line, "pb\n", ft_strlen2(line)))
        ft_pb(&(*bonus)->a, &(*bonus)->b);
}