/*
--simple fuerza el uso de el algoritmo O(n 2) seleccionado.
 */

 //vamos a utilizar Adaptación del orden por inserción o Métodos simples de extracción del mínimo/máximo que es lo mismo

 //Buscamos cual es el número menor, lo subimos arriba, dividimos el tamaño entre 2, si hay menos movimientos para arriba hacemos ra, y si hay menos por abajo rra en stack a.
 // hacemos pb y movemos a stack b
 //Una vez colocamdos toodos, movemos de b a a con pa
 //como el ultimo es el mayor, al moverlo a stack a, el primero será el mas pequeño y el utimo el mas grande


#include "push_swap.h"
#include <stdio.h>

void simple_extraccion(t_list **a, t_list **b)
{
	t_list	*nodo_b;
	t_list	*nodo_a;
	t_list	*comparate_nodo_a;
	void	*temp_mayor;
	int		size;

	nodo_a = *a;
	comparate_nodo_a = *a;

	comparate_nodo_a = comparate_nodo_a->next;
	nodo_b = *b;

	while(nodo_a)
	{
		size = (ft_size_lis(nodo_a) / 2);
		temp_mayor = nodo_a;

		if (nodo_a->value > comparate_nodo_a->value)
		{
			// temp_mayor = &nodo_a;
			comparate_nodo_a = comparate_nodo_a->next;
		}
		else
		{
			temp_mayor = comparate_nodo_a;
			nodo_a = temp_mayor;

		}
		comparate_nodo_a = comparate_nodo_a->next;

	}



}

