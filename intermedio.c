/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intermedio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:02:23 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/13 03:42:29 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>




static void	ft_reset_index(t_list **a)
{
	t_list	*nodo_a;

	nodo_a = *a;
	while (nodo_a)
	{
		nodo_a->index = -1;
		nodo_a = nodo_a->next;
	}
}

// t_list	*ft_new_list(t_list *a, int index)
// {
// 	a->index = index;
// 	return (a);
// }

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

//Recorremos la lista poniendo un index 0 siendo el número mayor;
static void index_mayor_a_menor(t_list **a)
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

static void	semi_colocacion_b(t_list **a, t_list **b)
{
	int	r_size;
	int	i;
	
	r_size = raiz_size(ft_size_lis(*a));
	i = 0;
	
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ft_pb(a, b);
			if (ft_size_lis(*b) > 1)
				ft_rb(b);     // Empujamos los mas pequeños al fondo por arriba, que se jodan ajajja
			i++;
		}
		else if ((*a)->index <= i + r_size)
		{
			ft_pb(a, b);
			i++;
		}
		else
			ft_ra(a);
	}
}

/*
Para 100: r_size = raiz * 1.5 (aprox 15-18 números por chunk).
Para 500: r_size = raiz * 2.0 (aprox 40-45 números por chunk).

n = ft_size_lis(*a);
	// Ajuste dinámico para máxima puntuación
	if (n <= 100)
		r_size = n / 6; // Chunks de ~16
	else
		r_size = n / 14; // Chunks de ~35

AJustando eso podriamos bajar el numero de pasos a dar si se desborda
*/



static void	pasar_b_a(t_list **a, t_list **b)
{
	t_list	*nodo_b;
	int		i;
	int		count;

	i = 0;
	while (*b)
	{
		nodo_b = *b;
		count = 0;
		while (nodo_b && nodo_b->index != i)		//probar (nodo_b->index != i && nodo_b)
		{
			nodo_b = nodo_b->next;
			count++;
		}	
		if (count <= ft_size_lis(*b) / 2)
		{
			while ((*b)->index != i)
				ft_rb(b);
		}
		else
			while ((*b)->index != i)
				ft_rrb(b);
		ft_pa(a,b);
		i++;
	}
}


// int	find_index_to_a(t_list *b)
// {
// 	int	max;

// 	max = b->index;

// 	while(b)
// 	{
// 		if ( b->index > max)
// 			max = b->index;
// 		b = b->next;
// 	}
// 	return (max);
// }



void medium_extraccion(t_list **a, t_list **b)
{

	ft_reset_index(a);
	index_mayor_a_menor(a);

	semi_colocacion_b(a, b);

	pasar_b_a(a, b);

}
	
// 	int	r_size;
// 	int	i;

// 	index_mayor_a_menor(a);
// 	r_size = raiz_size(ft_size_lis(*a));
// 	i = 0;


// 	while(*a)
// 	{
// 		if ((*a)->index <= i)
// 		{
// 			ft_pb();
// 			if (ft_size_lis(*b) > 1)
// 				ft_rb(b);
// 			i++;
// 		}	 
// 		else if ((*a)->index <= i + r_size)
// 		{
// 			ft_pb();
// 			i++;
// 		}
// 		else
// 			ft_ra();
		

// 	}
// 	while (*b)
// 	{

// 	}
// 		ft_pa();
// }


