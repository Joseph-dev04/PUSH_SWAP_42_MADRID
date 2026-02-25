/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:36:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 13:07:40 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			|| ft_strnstr(argv[i], "--adaptive", 12))
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
