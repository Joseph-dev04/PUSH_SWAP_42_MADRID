/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:51:25 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/13 03:39:34 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
--simple fuerza el uso de el algoritmo O(n 2) seleccionado.
 */

 //vamos a utilizar Adaptación del orden por inserción o Métodos simples de extracción del mínimo/máximo que es lo mismo

 //Buscamos cual es el número menor, lo subimos arriba, dividimos el tamaño entre 2, si hay menos movimientos para arriba hacemos ft_ra, y si hay menos por abajo rra en stack a.
 // hacemos pb y movemos a stack b
 //Una vez colocamdos toodos, movemos de b a a con pa
 //como el ultimo es el mayor, al moverlo a stack a, el primero será el mas pequeño y el utimo el mas grande


#include "push_swap.h"
#include <stdio.h>

// static void	rotar_a(t_list **a, t_list *nodo_a, int min_posicion)
// {
// 	int	size;

// 	if (ft_size_lis(*a) % 2 == 1)
// 		size = (ft_size_lis(*a) / 2) + 1;
// 	else
// 		size = ft_size_lis(*a) / 2;
// 	if (min_posicion > size)
// 	{
// 		while ((*a)->value != nodo_a->value)
// 			ft_rra(a);
// 	}
// 	else
// 	{
// 		while ((*a)->value != nodo_a->value)
// 			ft_ra(a);
// 	}
// }

// void	simple_extraccion(t_list **a, t_list **b)
// {
// 	t_list	*nodo_a;
// 	t_list	*comparate_nodo_a;
// 	int		posicion;
// 	int		min_posicion;

// 	while (*a)
// 	{
// 		nodo_a = *a;
// 		comparate_nodo_a = (*a)->next;
// 		posicion = 1;
// 		min_posicion = 0;
// 		while (comparate_nodo_a)
// 		{
// 			if (nodo_a->value > comparate_nodo_a->value)
// 			{
// 				nodo_a = comparate_nodo_a;
// 				min_posicion = posicion;
// 			}
// 			posicion++;
// 			comparate_nodo_a = comparate_nodo_a->next;
// 		}
// 		rotar_a(a, nodo_a, min_posicion);
// 		ft_pb(a, b);
// 	}
// 	while (*b)
// 		ft_pa(a, b);
// }





// void simple_extraccion(t_list **a, t_list **b)
// {
// 	t_list	*nodo_a;
// 	t_list	*comparate_nodo_a;
// 	int		size;
// 	int		posicion;
// 	int		min_posicion;
	
// 	while(*a)
// 	{
// 		nodo_a = *a;
// 		comparate_nodo_a = (*a)->next;
// 		posicion = 1;
// 		min_posicion = 0;
		
// 		while(comparate_nodo_a)
// 		{
// 			if (nodo_a->value > comparate_nodo_a->value)
// 			{
// 				nodo_a = comparate_nodo_a;
// 				min_posicion =posicion;
// 			}
// 			posicion++;
// 			comparate_nodo_a = comparate_nodo_a->next;
// 		}
// 		if (ft_size_lis(*a) % 2 == 1)	
// 			size = (ft_size_lis(*a) / 2) + 1;
// 		else
// 			size = ft_size_lis(*a) / 2;
			
// 		if (min_posicion > size)
// 			while ((*a)->value != nodo_a->value)
// 				ft_rra(a);
// 		else
// 			while ((*a)->value != nodo_a->value)
// 				ft_ra(a);
// 		ft_pb(a, b);
// 	}
// 	while(*b)
// 	{
// 		ft_pa(a, b);
// 	}
// }

void simple_extraccion(t_list **a, t_list **b)
{
	t_list	*nodo_min;
	t_list	*tmp;
	int		size;
	int		pos;
	int		min_pos;

	while (*a)
	{
		nodo_min = *a;
		tmp = (*a)->next;
		pos = 1;
		min_pos = 0;

		while (tmp)
		{
			if (tmp->value < nodo_min->value)
			{
				nodo_min = tmp;
				min_pos = pos;
			}
			pos++;
			tmp = tmp->next;
		}

		size = ft_size_lis(*a);

		if (min_pos <= size / 2)
		{
			while (*a != nodo_min)
				ft_ra(a);
		}
		else
		{
			while (*a != nodo_min)
				ft_rra(a);
		}

		ft_pb(a, b);
	}

	while (*b)
		ft_pa(a, b);
}

