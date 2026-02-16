/*
--simple fuerza el uso de el algoritmo O(n 2) seleccionado.
 */

 //vamos a utilizar Adaptación del orden por inserción o Métodos simples de extracción del mínimo/máximo que es lo mismo

 //Buscamos cual es el número menor, lo subimos arriba, dividimos el tamaño entre 2, si hay menos movimientos para arriba hacemos ra, y si hay menos por abajo rra en stack a.
 // hacemos pb y movemos a stack b
 //Una vez colocamdos toodos, movemos de b a a con pa
 //como el ultimo es el mayor, al moverlo a stack a, el primero será el mas pequeño y el utimo el mas grande


#include "push_swap.h"

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

