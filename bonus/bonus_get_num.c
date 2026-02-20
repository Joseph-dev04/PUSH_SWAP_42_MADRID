/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:56:14 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 17:25:36 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_brench_status(int arc, char **argv, int *position)
{
	int i;
	int	bench;

	i = 1;
	bench = 0;
	while (i < arc)
	{
		if (ft_strnstr(argv[i], "--bench", ft_strlen(argv[i])))
		{
			*position = i;
			bench++;
		}
		i++;
	}
	return (bench);
}

int	ft_module_status(int arc, char **argv, int *position)
{
	int	i;
	int	flags;

	i = 1;
	flags = 0;
	while (i < arc)
	{
		if (ft_strnstr(argv[i], "--simple", 8))
		{
			*position = i;
			flags++;
		}
		if (ft_strnstr(argv[i], "--medium", 8))
		{
			*position = i;
			flags++;
		}
		if (ft_strnstr(argv[i], "--complex", 9))
		{
			*position = i;
			flags++;
		}
		if (ft_strnstr(argv[i], "--adaptative", 13))
		{
			*position = i;
			flags++;
		}
		i++;
	}
	return (flags);
}

int	comprobar_duplicados(t_list	**a)
{
	t_list	*n;
	t_list	*move;

	n = *a;
	while (n)
	{
		move = n->next;
		while (move)
		{
			if(n->value == move->value)
				return (0);
			move = move->next;
		}
		n = n->next;
	}
	return (1);
}

int	ft_itoa_pro(char *str, t_list **a, int index, int *i)
{
	int		j;
	char	*num;
	t_list	*new;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (!ft_isdigit(str[j]))
		return (-1);
	while (ft_isdigit(str[j]))
		j++;
	if (str[j] != ' ' && str[j] != '\0')
		return (-1);
	num = ft_substr2(str, 0, j);
	*i += j;
	new = ft_new_list(ft_atoi(num), index);
	free(num);
	ft_add_back(a, new);
	return (0);
}

int	ft_get_num(char *list_num, t_list **a)
{
	int	i;

	i = 0;
	while (list_num[i])
	{
		while (list_num[i] == ' ')
			i++;

		if (list_num[i] == '\0')
			break ;
		if (list_num[i] >= '\t' && list_num[i] <= '\r')
			return (ft_error());
		if (ft_isdigit(list_num[i])
			|| (((list_num[i] == '-' || list_num[i] == '+')
			&& ft_isdigit(list_num[i + 1]))))
		{
			if (ft_itoa_pro(&list_num[i], a, 0, &i) == -1)
				return (ft_error());
			if (list_num[i] && list_num[i] != ' ')
				return (ft_error());
		}
		else
			return (ft_error());
	}
	if (comprobar_duplicados(a) == 0)
		return (ft_error());
	return (0);
}

/*
int	ft_get_num(char *list_num, t_list **a)
{
	int		i_comi;
	int	i;

	i = 0;
	i_comi = 0;
	while (list_num[i])
	{
		if (list_num[i] == '-' && !ft_isdigit(list_num[i + 1]))
			return (ft_error());
		else if ((list_num[i] != ' ' && !ft_isdigit(list_num[i])) && list_num[i] != '-')
			return (ft_error());
		else if (list_num[i] >= '\t' && list_num[i] <= '\r')
			return (ft_error());
		else if (list_num[i] == ' ')
			i++;
		if (ft_isdigit(list_num[i]) || (list_num[i] == '-' && ft_isdigit(list_num[i + 1])))
			ft_itoa_pro(&list_num[i], a, 0, &i);
		else if (!(list_num[i] == '-' && ft_isdigit(list_num[i + 1])))
			return (ft_error());
		if (list_num[i])
			i++;
	}
	if (comprobar_duplicados(a) == 0)
		return (ft_error());
	return (0);
}
*/

float compute_disorder(t_list *stack_a)
{
	long long		mistakes;
	long long		total_pairs;
	t_list			*n_nodo_a;
	t_list			*n_nodo_b;

	
	mistakes = 0;
	total_pairs = 0;
	n_nodo_a = stack_a;
	n_nodo_b = n_nodo_a;
	while (n_nodo_a != NULL)
	{
		n_nodo_b = n_nodo_a->next;
		while (n_nodo_b != NULL)
		{
			total_pairs++;
			if (n_nodo_a->value > n_nodo_b->value)
				mistakes++;
			n_nodo_b = n_nodo_b->next;
		}
		n_nodo_a = n_nodo_a->next;
	}
	if (total_pairs == 0)
		return (0.0);
	printf("%f", ((float)mistakes / (float)total_pairs));
	return ((float)mistakes / (float)total_pairs);
	//return (float)((double)mistakes / (double)total_pairs);
}
