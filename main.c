/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/18 19:08:20 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int contador = 0;

int	charge_num(char **argv, int arc, t_principal **principal, int flag)
{
	int	size;
	int	i;

	i = 1;
	//printf("%i\n",arc);
	while (i < arc)
	{
		if (ft_strnstr(argv[i], "--bench", ft_strlen(argv[flag])))
			i++;
		if (i != flag && i < arc)
		{
			//printf("entro %i\n", i);
			size = ft_get_num(argv[i], &(*principal)->a);
			if (size == -1)
				return (1);
		}
		i++; 
	}
	return (0);
}

void	ft_type_algoritm(char **argv, int arc, t_principal **principal, int flag)
{

	if (ft_strnstr(argv[flag], "--simple", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			simple_extraccion(principal);
	}
	else if (ft_strnstr(argv[flag], "--medium", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			medium_extraccion(principal);
	}
	else if (ft_strnstr(argv[flag], "--complex", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			ft_radix(principal, ft_size_lis((*principal)->a));
	}
	else
	{
		if (!charge_num(argv, arc, principal, flag))
			ft_adaptative(principal);
	}
}

void	ft_struct(t_principal **principal)
{
	*principal = malloc(sizeof(t_principal));
	if (!*principal)
		return ;
	(*principal)->bench = malloc(sizeof(t_stats));
    if (!(*principal)->bench)
    {
        free(*principal);
        *principal = NULL;
        return ;
    }
	// (*principal)->bench = NULL;
	(*principal)->bench->pa_count = 0;
	(*principal)->bench->pb_count = 0;
	(*principal)->bench->ra_count = 0;
	(*principal)->bench->rb_count = 0;
	(*principal)->bench->rr_count = 0;
	(*principal)->bench->rra_count = 0;
	(*principal)->bench->rrb_count = 0;
	(*principal)->bench->rrr_count = 0;
	(*principal)->bench->sa_count = 0;
	(*principal)->bench->sb_count = 0;
	(*principal)->bench->ss_count = 0;
	(*principal)->bench->total_count = 0;
	(*principal)->bench->sizea = 0;
	(*principal)->a = NULL;
	(*principal)->b = NULL;
}

int	main(int arc, char **argv)
{
	// t_list	*a;
	// t_list	*b;
	int	bench;
	int	flag;
	t_principal *principal;

	principal = NULL;
	bench = 0;
	flag = 0;
	ft_struct(&principal);
	if (arc > 1)
	{
		if (ft_brench_status(arc, argv, &bench) > 1 || ft_module_status(arc, argv, &flag) > 1)
			return (ft_error());
		//printf("%i %i\n", flag, bench);
		ft_type_algoritm(argv, arc, &principal, flag);
        principal->b = principal->a;
        while (principal->b)
        {
			printf("%i ", principal->b->value);
            principal->b = principal->b->next;
        }
		ft_free_a(principal->a);
    }
	// printf("\ncontador:%i", contador);
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