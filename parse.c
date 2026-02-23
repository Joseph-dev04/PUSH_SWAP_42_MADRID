/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:36:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 13:36:00 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

int	ft_brench_status(int arc, char **argv, int *position)
{
	int	i;
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
		if (ft_strnstr(argv[i], "--simple", 8)
			|| ft_strnstr(argv[i], "--medium", 8)
			|| ft_strnstr(argv[i], "--complex", 9)
			|| ft_strnstr(argv[i], "--adaptative", 12))
		{
			*position = i;
			flags++;
		}
		i++;
	}
	return (flags);
}

int	duplicate(t_list	**a)
{
	t_list	*n;
	t_list	*move;

	n = *a;
	while (n)
	{
		move = n->next;
		while (move)
		{
			if (n->value == move->value)
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
	num = ft_substr(str, 0, j);
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
	return (0);
}
