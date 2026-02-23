/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:31:38 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 17:37:04 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (duplicate(&(*principal)->a) == 0)
				return (ft_error());
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
			simple_extraction(principal);
	}
	else if (ft_strnstr(argv[flag], "--medium", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			medium_extraccion(principal);
	}
	else if (ft_strnstr(argv[flag], "--complex", ft_strlen(argv[flag])))
	{
		if (!charge_num(argv, arc, principal, flag))
			push_back(principal);
	}
	else
	{
		if (!charge_num(argv, arc, principal, flag))
			ft_adaptative(principal);
	}
}

static void	init_bench(t_stats **bench)
{
	(*bench)->pa_count = 0;
	(*bench)->pb_count = 0;
	(*bench)->ra_count = 0;
	(*bench)->rb_count = 0;
	(*bench)->rr_count = 0;
	(*bench)->rra_count = 0;
	(*bench)->rrb_count = 0;
	(*bench)->rrr_count = 0;
	(*bench)->sa_count = 0;
	(*bench)->sb_count = 0;
	(*bench)->ss_count = 0;
	(*bench)->total_count = 0;
	(*bench)->simple = 0;
	(*bench)->medium = 0;
	(*bench)->complex = 0;
	(*bench)->adaptative = 0;
	(*bench)->compute_disorder = 0.0f;
}

void	ft_struct(t_principal **principal)
{
	*principal = malloc(sizeof(t_principal));
	if (!*principal)
		return ;
	(*principal)->a = NULL;
	(*principal)->b = NULL;
	(*principal)->bench = malloc(sizeof(t_stats));
	if (!(*principal)->bench)
	{
		free(*principal);
		*principal = NULL;
		return ;
	}
	init_bench(&(*principal)->bench);
}

int	main(int arc, char **argv)
{
	int			bench;
	int			flag;
	t_principal	*principal;

	principal = NULL;
	bench = 0;
	flag = 0;
	if (arc > 1)
	{
		ft_struct(&principal);
		if (ft_brench_status(arc, argv, &bench) > 1
			|| ft_module_status(arc, argv, &flag) > 1)
			return (ft_error());
		ft_type(argv, arc, &principal, flag);
		if (bench)
			bench_union(&principal);
		ft_free_a(principal->a);
		free(principal->bench);
		free(principal);
	}
	return (0);
}
