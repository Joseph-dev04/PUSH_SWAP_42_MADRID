/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:34:37 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/10 12:38:31 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
extern int contador;
void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a);
	ft_sb(b);
	contador++;
	write(1, "ss\n", 3);
}

void	ft_sa(t_list **a)
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
	contador++;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	contador++;
	write(1, "sb\n", 3);
}
