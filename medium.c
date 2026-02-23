/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:11:53 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/23 16:19:24 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static int	raiz_size(int size)
{
	int	i;

	i = 1;
	if (size <=0)
		return (0);
	if (size == 1)
		return (1);
	while ((i * i) <= size)
		i++;
	return (i- 1);
}

static void	index_mayor_a_menor(t_list **a)
{
	t_list	*nodo_a;
	t_list	*comparate_nodo_a;
	int		index;
	int		size;

	size = ft_size_lis(*a);
	index = size - 1;
	while (index >= 0)
	{
		nodo_a = *a;
		comparate_nodo_a = NULL;
		while (nodo_a)
		{
			if (nodo_a->index == -1)
			{
				if (comparate_nodo_a == NULL || nodo_a->value < comparate_nodo_a->value)
					comparate_nodo_a = nodo_a;
			}
			nodo_a = nodo_a->next;
		}
		if (comparate_nodo_a)
		{
			comparate_nodo_a->index = index;
			index--;
		}
	}
}

static void	semi_colocacion_b(t_principal **principal)
{
	int	r_size;
	int	i;

	r_size = raiz_size(ft_size_lis((*principal)->a));
	i = 0;
	while ((*principal)->a)
	{
		if ((*principal)->a->index <= i)
		{
			ft_pb(principal, 0);
			if (ft_size_lis((*principal)->b) > 1)
				ft_rb(principal, 0);
			i++;
		}
		else if ((*principal)->a->index <= i + r_size)
		{
			ft_pb(principal, 0);
			i++;
		}
		else
			ft_ra(principal, 0);
	}
}

static void	pasar_b_a(t_principal **principal)
{
	t_list	*nodo_b;
	int		i;
	int		count;

	i = 0;
	while ((*principal)->b)
	{
		nodo_b = (*principal)->b;
		count = 0;
		while (nodo_b && nodo_b->index != i)
		{
			nodo_b = nodo_b->next;
			count++;
		}
		if (count <= ft_size_lis((*principal)->b) / 2)
		{
			while ((*principal)->b->index != i)
				ft_rb(principal, 0);
		}
		else
			while ((*principal)->b->index != i)
				ft_rrb(principal, 0);
		ft_pa(principal, 0);
		i++;
	}
}

void medium_extraccion(t_principal **principal)
{
	int size;

	if (!principal || !*principal || !(*principal)->a)
	{
		return ;
	}
	size = ft_size_lis((*principal)->a);
	(*principal)->bench->compute_disorder = compute_disorder((*principal)->a);
	(*principal)->bench->medium = 1;
	if (size <= 3)
	{
		simple_small_extraction(principal);
		return ;
	}
	ft_reset_index(&(*principal)->a);
	index_mayor_a_menor(&(*principal)->a);
	semi_colocacion_b(principal);
	pasar_b_a(principal);
}
