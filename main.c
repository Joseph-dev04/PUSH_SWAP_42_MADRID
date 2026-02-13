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
/*
void	ft_type_algotim(char **argv)
{
	if (ft_strnstr(argv[1], "simple", ft_strlen(argv[1])))
		simple_extraccion_final();
	else if (ft_strnstr(argv[1], "intermedio", ft_strlen(argv[1])))
		ft_intermedio();
	else if (ft_strnstr(argv[1], "complejo", ft_strlen(argv[1])))
		ft_radix_sort();
	else if (ft_strnstr(argv[1], "extra?", ft_strlen(argv[1])))
		ft_turk();
	else
		ft_default();
}
*/
int	main(int arc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
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
		//ft_type_algoritm(&argv);
		//ft_radix(&a, &b);
       // printf("índice de desorden: %f\n", compute_disorder(a));
        b = a;
        while (b)
        {
			printf("%i\n", b->value);
            b = b->next;
        }
		ft_free(a);
    }
    return (0);
}
