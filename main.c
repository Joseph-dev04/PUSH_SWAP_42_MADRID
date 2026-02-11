/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/10 18:35:51 by aitorres         ###   ########.fr       */
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
        printf("índice de desorden: %f\n", compute_disorder(a));
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
