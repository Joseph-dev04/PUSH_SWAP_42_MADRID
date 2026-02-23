/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:37:06 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 14:47:13 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap_bonus.h"

static void	ft_sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static void	ft_sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

static void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_check_swap(char *line, t_checker **bonus)
{
	if (ft_strnstr(line, "sa\n", ft_strlen2(line)))
		ft_sa(&(*bonus)->a);
	else if (ft_strnstr(line, "sb\n", ft_strlen2(line)))
		ft_sb(&(*bonus)->b);
	else if (ft_strnstr(line, "ss\n", ft_strlen2(line)))
		ft_ss(&(*bonus)->a, &(*bonus)->b);
}
