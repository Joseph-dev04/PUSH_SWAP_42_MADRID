/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 14:42:03 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	charge_num(char **argv, int arc, t_principal **principal, int flag)
{
	int	size;
	int	i;

	i = 1;
	while (i < arc)
	{
		if (ft_strnstr(argv[i], "--bench", ft_strlen(argv[flag])))
			i++;
		if (i != flag && i < arc)
		{
			size = ft_get_num(argv[i], &(*principal)->a);
			if (size == -1)
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_type(char **argv, int arc, t_principal **principal, int flag)
{

	if (ft_strnstr(argv[flag], "--simple", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			simple_extraccion(principal);
	}
	else if (ft_strnstr(argv[flag], "--medium", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			medium_extraccion(principal);
	}
	else if (ft_strnstr(argv[flag], "--complex", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			ft_radix(principal, ft_size_lis((*principal)->a));
	}
	else
	{
		if (!charge_num(argv, arc, principal, flag))
			ft_adaptative(principal);
	}
}

void	ft_struct(t_principal **principal)
{
	*principal = malloc(sizeof(t_principal));
	if (!*principal)
		return ;
	(*principal)->bench = malloc(sizeof(t_stats));
	if (!(*principal)->bench)
	{
		free(*principal);
		*principal = NULL;
		return ;
	}
	(*principal)->bench->pa_count = 0;
	(*principal)->bench->pb_count = 0;
	(*principal)->bench->ra_count = 0;
	(*principal)->bench->rb_count = 0;
	(*principal)->bench->rr_count = 0;
	(*principal)->bench->rra_count = 0;
	(*principal)->bench->rrb_count = 0;
	(*principal)->bench->rrr_count = 0;
	(*principal)->bench->sa_count = 0;
	(*principal)->bench->sb_count = 0;
	(*principal)->bench->ss_count = 0;
	(*principal)->bench->total_count = 0;
	(*principal)->a = NULL;
	(*principal)->b = NULL;
	(*principal)->bench->simple = 0;
	(*principal)->bench->medium = 0;
	(*principal)->bench->complex = 0;
	(*principal)->bench->adaptative = 0;
}

int	main(int arc, char **argv)
{
	int			bench;
	int			flag;
	t_principal	*principal;

	principal = NULL;
	bench = 0;
	flag = 0;
	ft_struct(&principal);
	if (arc > 1)
	{
		if (ft_brench_status(arc, argv, &bench) > 1
			|| ft_module_status(arc, argv, &flag) > 1)
			return (ft_error());
		ft_type(argv, arc, &principal, flag);
		principal->b = principal->a;
		while (principal->b)
			principal->b = principal->b->next;
		ft_free_a(principal->a);
	}
	return (0);
}
