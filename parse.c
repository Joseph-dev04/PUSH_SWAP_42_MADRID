/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:36:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/10 18:39:41 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_itoa_pro(char **str, t_list **a, int index)
{
	int		i;
	char	*num;
	t_list	*new;

	i = 0;
	while (ft_isdigit((*str)[i]))
		i++;
	num = ft_substr(*str, 0, i);
	*str = *str + i;
	new = ft_new_list(ft_atoi(num), index);
	free(num);
	ft_add_back(a, new);
}

// "    123  "
// int	ft_get_num(char *list_num, t_list **a)
// {
// 	int	index;

// 	index = 0;
// 	while (*list_num)
// 	{
// 		if (*list_num >= '\t' && *list_num <= '\r')
// 		{//printf("%c\n", *list_num);
// 			return (ft_error());
// 		}
// 		if (*list_num != ' ' && !ft_isdigit(*list_num))
// 		{//printf("%c\n", *list_num);
// 			return (ft_error());
// 		}
// 		if (*list_num >= '0' && *list_num <= '9')
// 		{
// 			//printf("%i\n", index);
// 			ft_itoa_pro(&list_num, a, index);
// 		}
// 		if (*list_num)
// 			list_num++;
// 		index++;
// 	}
// 	return (index);
// }


static int comprobar_duplicados(t_list **a)
{
	t_list	*n_nodo;
	t_list	*sub_n_nodo;

	n_nodo = *a;
	sub_n_nodo = *a;
	while (n_nodo != NULL)
	{
		sub_n_nodo = *a;
		sub_n_nodo = n_nodo->next;
		while (sub_n_nodo != NULL)
		{
			if (n_nodo->value == sub_n_nodo->value)
				return (0);
			sub_n_nodo = sub_n_nodo->next;
		}
		sub_n_nodo = *a;
		n_nodo = n_nodo->next;
	}
	return (1);
}

int	ft_get_num(char *list_num, t_list **a)
{
	int		i_comi;
	int	index;

	index = 0;

	i_comi = 0;
	while (*list_num)
	{
		while (*list_num)
		{
			if (ft_isdigit(*list_num) || (*list_num == '-' && ft_isdigit(*(list_num + 1))))
				break ;
			if (*list_num != ' ' && *list_num != '"' && *list_num != '-')
			{
				ft_free(*a);
				return (ft_error());
			}
			if (*list_num == '"')
				i_comi++;
			list_num++;
		}

		
		if (*list_num)
		{
			ft_itoa_pro(&list_num, a, index);
		}
		// list_num++;
		index++;
	}
	if (i_comi % 2 != 0)
	{
		ft_free(*a);
		return (ft_error());
	}
	if (comprobar_duplicados(a) == 0)
	{
		ft_free(*a);
		return (ft_error());
	}
	return (index);
}
