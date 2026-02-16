/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/13 10:06:08 by jopajuel         ###   ########.fr       */
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
        printf("índice de desorden: %f\n", compute_disorder(a));
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
