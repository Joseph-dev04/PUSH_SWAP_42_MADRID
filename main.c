/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/17 18:07:31 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int contador = 0;

int	charge_num(char **argv, int arc, t_list **a, int i)
{
	int	size;

	while (i < arc)
	{
		size = ft_get_num(argv[i], a);
		if (size == -1)
			return (1);
		i++; 
	}
	return (0);
}

void	ft_type_algoritm(char **argv, int arc, t_list **a, t_list **b)
{
	if (ft_strnstr(argv[1], "--simple", ft_strlen(argv[1])))
	{
		if (!charge_num(argv, arc, a, 2))
			simple_extraccion(a,b);
	}
	else if (ft_strnstr(argv[1], "--medium", ft_strlen(argv[1])))
	{
		if (!charge_num(argv, arc, a, 2))
			medium_extraccion(a, b);
	}
	else if (ft_strnstr(argv[1], "--complex", ft_strlen(argv[1])))
	{
		if (!charge_num(argv, arc, a, 2))
			ft_radix(a, b, ft_size_lis(*a));
	}
	/*else if (ft_strnstr(argv[1], "--adaptive", ft_strlen(argv[1])))
	{
		if (!charge_num(argv, arc, a, b, 2))
			return ;
	}
	else
	{
		if (!charge_num(argv, arc, a, b, 2))
		return ;
	}*/
}

int	main(int arc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (arc > 1)
	{
		ft_type_algoritm(argv, arc, &a, &b);
        // printf("índice de desorden: %f\n", compute_disorder(a));
        b = a;
        while (b)
        {
			printf("value :%i index: %i\n", b->value, b->index);
            b = b->next;
        }
		ft_free_a(a);
    }
	printf("%i\n", contador);
    return (0);
}


/*CON ESTE MAIN FUNCIONA PPRQUE PRIMER AGREGA CALCULA EL DESORDEN Y LUEGO YA ASIGNA, PPEEEERO NO VALE PARA NUESTRO CÓDIGO*/
/* int	main(int arc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (arc > 1)
	{
		// 1. Cargar los números en el stack 'a' (sin ordenar)
		if (charge_num(argv, arc, &a, 2) != 0)
		{
			ft_free_a(a);
			return (1); // Error en carga
		}

		// 2. Calcular y mostrar el índice de desorden ANTES de ordenar
		printf("índice de desorden: %f\n", compute_disorder(a));

		// 3. Ejecutar el algoritmo de ordenación según argv[1]
		if (ft_strnstr(argv[1], "--simple", ft_strlen(argv[1])))
			simple_extraccion(&a, &b);
		else if (ft_strnstr(argv[1], "--medium", ft_strlen(argv[1])))
			medium_extraccion(&a, &b);
		else if (ft_strnstr(argv[1], "--complex", ft_strlen(argv[1])))
			ft_radix(&a, &b, ft_size_lis(a));

		// 4. Imprimir valores finales (opcional)
		t_list *temp = a;
		while (temp)
		{
			printf("value :%i index: %i\n", temp->value, temp->index);
			temp = temp->next;
		}

		ft_free_a(a);
	}
	printf("%i\n", contador);
	return (0);
} */

// comprueba ./a.out --complex 10 6 -88888 -8 -1 -4 -2147447 +1

//el primer numero no lo ordena