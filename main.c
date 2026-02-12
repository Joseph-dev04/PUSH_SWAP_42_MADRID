/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/12 12:41:26 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// int	main(int arc, char **argv)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	int		i;
	
// 	a = NULL;
// 	b = NULL;
// 	if (arc != 1)
// 	{
// 		i = 0;
// 		if (ft_get_num(argv[i], &a))
// 		{
// 			// ft_sa(&a);
// 			while (a)
// 			{
// 				printf("%i\n", a->value);
// 				a = a->next;
// 			}
// 		}
// 		else
// 		{
// 			// ft_free(a);
// 			return (-1);
// 		}
// 	}
// 	return (0);
// }

int main(int arc, char **argv)
{
    t_list  *a;
    t_list  *b; 
    int     i;
	int		size;
    
    a = NULL;
	b = NULL;
    if (arc > 1)
    {
        i = 1;
        while (i < arc)
        {
            size = ft_get_num(argv[i], &a);
            if (size == -1)
                return (1);
            i++;
        }
		ft_radix(&a, &b);
        printf("índice de desorden: %f\n", compute_disorder(a));
        //b = a;
        while (b)
        {
			printf("%i\n", b->value);
            b = b->next;
        }
		ft_free(a);
    }
    return (0);
}/*
Entiendo perfectamente. Quieres visualizar la "maquinaria" interna de la toma de decisiones. Olvidémonos del código y miremos los engranajes: cómo un nodo específico en A evalúa sus opciones para aterrizar en B de la manera más barata posible.

Imagina que estamos a mitad del proceso. Tenemos los siguientes stacks:

Stack A: [15, 2, 50, 4] (15 es la cima, size = 4)

Stack B: [10, 8, 1, 30] (10 es la cima, size = 4)

Vamos a analizar el coste de mover el número 50 de Stack A hacia el Stack B.
1. Identificar el Objetivo (Target)
Para el 50 (en Stack A), su "mejor amigo" en Stack B es el número más grande de entre los que son menores que él.

En B tenemos: 10, 8, 1, 30.

El más grande de los menores a 50 es el 30.

Misión: Poner el 50 en la cima de A y el 30 en la cima de B para ejecutar pb.
2. Análisis de Posiciones y Medianas
Nodo 50 (A): Está en la posición 2 (índice 0-1-2-3).
La mediana de A es 2. El 50 está justo en el límite (lo trataremos como "abajo" para este ejemplo de cálculo)
.Distancia arriba (ra): 2 movimientos
.Distancia abajo (rra): 2 movimientos ($4 - 2$).
Nodo 30 (B): Está en la posición 3 (el último)
.La mediana de B es 2. El 30 está claramente "abajo"
.Distancia arriba (rb): 3 movimientos
.Distancia abajo (rrb): 1 movimiento ($4 - 3$).
3. El Menú de Costes (Los 4 Escenarios)
Calculamos cuánto nos costaría llevar al 50 y al 30 a sus respectivas cimas según la dirección:
Escenario,Lógica,Cálculo,Coste Total
Ambos arriba (RR),Usar ra y rb,"max(2,3)",3 (3 movimientos)
Ambos abajo (RRR),Usar rra y rrb,"max(2,1)",2 (2 movimientos)
A arriba / B abajo,Usar ra y rrb,2+1,3 (3 movimientos)
A abajo / B arriba,Usar rra y rb,2+3,5 (5 movimientos)
Ganador: El escenario RRR (Ambos abajo) con un coste de 2.
4. Ejecución del Proceso Oportunista
Una vez que el algoritmo decide que el 50 es el más barato (comparándolo con el coste de 15, 2 y 4), ejecuta esto:
Sincronización (Movimientos dobles):

Como ambos están "abajo", lanzamos rrr.

Tras el primer rrr: El 50 sube un puesto en A, el 30 sube un puesto en B (ahora el 30 ya es la cima de B).

Coste parcial: 1.
Finalización (Movimientos simples):

El 30 ya está donde queremos, pero al 50 le falta un paso.

Lanzamos rra (solo en A).

Coste parcial: 1.
El Salto:

Ahora el 50 está arriba de A y el 30 arriba de B.

Ejecutamos pb.

Coste final: 2 movimientos de rotación.
¿Qué ha pasado aquí?
Si hubieras movido el 50 a ciegas (solo mirando A), habrías hecho 2 ra. Luego habrías visto que el 30 está al fondo de B y habrías hecho un rrb. Total: 3 movimientos. Al calcular los 4 escenarios, el algoritmo "vio" que compartiendo un rrr, la operación se reducía a 2. Multiplica este ahorro por 500 números y ahí tienes la diferencia entre un aprobado raso y los 100 puntos.

¿Te gustaría que viéramos cómo cambia la lógica cuando el Stack B empieza a llenarse y el "target node" ya no es tan obvio?*/