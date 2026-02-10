/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/10 18:23:53 by aitorres         ###   ########.fr       */
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
    
    a = NULL;
	b = NULL;
    if (arc > 1)
    {
        i = 1;
        while (i < arc)
        {
            if (ft_get_num(argv[i], &a) == -1)
            {
                return (-1);
            }
            i++;
        }
        
        b = a;
        while (b)
        {
			//ft_free(a);
            printf("%i\n", b->value);
            b = b->next;
        }
    }
    return (0);
}
