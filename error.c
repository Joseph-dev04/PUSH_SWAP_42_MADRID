/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:10:05 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 10:10:05 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_elements_complex(t_principal **principal)
{
	int	first;
	int	second;
	int	third;

	first = (*principal)->a->index;
	second = (*principal)->a->next->index;
	third = (*principal)->a->next->next->index;
	if (first > second && second < third && first < third)
		ft_sa(principal, 0);
	else if (first > second && second > third)
	{
		ft_sa(principal, 0);
		ft_rra(principal, 0);
	}
	else if (first > second && second < third && first > third)
		ft_ra(principal, 0);
	else if (first < second && second > third && first < third)
	{
		ft_sa(principal, 0);
		ft_ra(principal, 0);
	}
	else if (first < second && second > third && first > third)
		ft_rra(principal, 0);
}

void	simple_small(t_principal **principal)
{
	int	size;

	size = ft_size_lis((*principal)->a);
	if (size <= 1)
		return ;
	if (size == 2 && (*principal)->a->index > (*principal)->a->next->index)
		ft_sa(principal, 0);
	else if (size == 3)
		sort_three_elements_complex(principal);
}

int	ft_error(void)
{
	write (2, "Error\n", 6);
	return (-1);
}
