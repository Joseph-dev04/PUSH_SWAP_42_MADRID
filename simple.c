/*
--simple fuerza el uso de el algoritmo O(n 2) seleccionado.
 */

 //vamos a utilizar Adaptación del orden por inserción o Métodos simples de extracción del mínimo/máximo que es lo mismo

 //Buscamos cual es el número menor, lo subimos arriba, dividimos el tamaño entre 2, si hay menos movimientos para arriba hacemos ra, y si hay menos por abajo rra en stack a.
 // hacemos pb y movemos a stack b
 //Una vez colocamdos toodos, movemos de b a a con pa
 //como el ultimo es el mayor, al moverlo a stack a, el primero será el mas pequeño y el utimo el mas grande


#include "push_swap.h"

void simple_extraccion_pequena(t_principal **principal)
{
	int		first;
	int		second;
	int 	third;
	int		size;

	size = ft_size_lis((*principal)->a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if ((*principal)->a->value > (*principal)->a->next->value)
			ft_sa(principal, 0);
		return ;
	}
	if (size == 3)
	{
		first = (*principal)->a->value;
		second = (*principal)->a->next->value;
		third = (*principal)->a->next->next->value;
		if (first > second && second > third)
		{
			ft_ra(principal, 0);
			if ((*principal)->a->value > (*principal)->a->next->value)
				ft_sa(principal, 0);
		}
		else if (second > first && second > third)
		{
			ft_rra(principal, 0);
			if ((*principal)->a->value > (*principal)->a->next->value)
				ft_sa(principal, 0);
		}
		else if (first > second)
			ft_sa(principal, 0);
	}
}
static int	get_min_pos(t_list *stack)
{
	t_list	*min_node;
	int		min_pos;
	int		current_pos;

	min_node = stack;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->value < min_node->value)
		{
			min_node = stack;
			min_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (min_pos);
}

static void	simple_extraccion_grande(t_principal **principal)
{
	int	min_pos;
	int	size;

	while ((*principal)->a)
	{
		min_pos = get_min_pos((*principal)->a);
		size = ft_size_lis((*principal)->a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ft_ra(principal, 0);
		}
		else
		{
			while (min_pos++ < size)
				ft_rra(principal, 0);
		}
		ft_pb(principal, 0);
	}
	while ((*principal)->b)
		ft_pa(principal, 0);
}

/* static void	simple_extraccion_grande(t_principal **principal)
{
	t_list	*nodo_min;
	t_list	*tmp;
	int		size;
	int		pos;
	int		min_pos;

	printf("ha entrado en grande\n");
	while ((*principal)->a)
	{
		nodo_min = (*principal)->a;
		tmp = (*principal)->a->next;
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
		size = ft_size_lis((*principal)->a);
		if (min_pos <= size / 2)
		{
			while ((*principal)->a != nodo_min)
				ft_ra(principal, 0);
		}
		else
		{
			while ((*principal)->a != nodo_min)
				ft_rra(principal, 0);
		}
		ft_pb(principal, 0);
	}
	while ((*principal)->b)
		ft_pa(principal, 0);
} */

void	simple_extraccion(t_principal **principal)
{
	int	size;

	size = ft_size_lis((*principal)->a);
	if (size <= 3)
		simple_extraccion_pequena(principal);
	else
		simple_extraccion_grande(principal);
}
