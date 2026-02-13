/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:51:37 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/13 11:13:39 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_num(t_list *a, int *list, int i, int j)
{
	int	num;

	if (i > j)
		return ;
	num =  (i + j) / 2;
	if (list[num] == a->value)
	{
		a->index = num;
		return ;
	}
	else if (a->value <  list[num])
		ft_index_num(a, list, i, num - 1);
	else
		ft_index_num(a, list, num + 1, j);
}

void	ft_indexacion(int *list_num, t_list **a, int i, int j)
{
	t_list	*temp;

	temp = a;
	while (!temp)
	{
		ft_index_num(temp, list_num, i, j);
		temp = temp->next;
	}
}

void	ft_logic(int **list, int inicio, int final)
{
	int	i;
	int	j;
	int	pivote;
	int	aux;

	i = inicio;
	j = final;
	pivote = *list[(inicio + final) / 2];
	while (i <= j)
	{
		while ((*list)[i] < pivote)
			i++;
		while ((*list)[j] > pivote)
			j--;
		if (i <= j)
		{
			aux = (*list)[i];
			(*list)[i] = (*list)[j];
			(*list)[j] = aux;
			i++;
			j--;
		}
	}
	if (inicio < j)
		ft_logic(list, inicio, j);
	if (final > i)
		ft_logic(list, i, final);
}

char	*ft_quicksort(int	*list_num, t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;

	i = 0;
	list_num = malloc(sizeof(int) * ft_size_lis(a));
	if (!list_num)
		return (NULL);
	temp = *a;
	while (temp)
	{
		list_num[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_logic(&list_num, 0, i);
	ft_indexacion(list_num, a, 0, i);
}

