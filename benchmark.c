/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:10:32 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 13:09:43 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bench_strategy(t_principal **principal)
{
	if ((*principal)->bench->adaptive == 1)
	{
		write(2, "[bench] Strategy: Adaptive / ", 31);
		if ((*principal)->bench->simple == 1)
			write(2, "O2\n", 3);
		else if ((*principal)->bench->medium == 1)
			write(2, "O(n√n)\n", 9);
		else if ((*principal)->bench->complex == 1)
			write(2, "O(nlogn)\n", 9);
	}
	else if ((*principal)->bench->simple == 1)
		write(2, "[bench] Strategy: Simple / O2\n", 30);
	else if ((*principal)->bench->medium == 1)
		write(2, "[bench] Strategy: Medium / O(n√n)\n", 36);
	else if ((*principal)->bench->complex == 1)
		write(2, "[bench] Strategy: Complex / O(nlogn)\n", 37);
}

static void	bench_total_ops(t_principal **principal)
{
	int		total_ops;

	if (!principal || !*principal || !(*principal)->bench)
		return ;
	total_ops = (*principal)->bench->total_count;
	write(2, "[bench] Total_ops: ", 19);
	ft_putnbr_fd2(total_ops);
	write(2, "\n", 1);
}

static void	bench_lineone_funciones(t_principal **principal)
{
	write(2, "[bench] sa:  ", 13);
	ft_putnbr_fd2((*principal)->bench->sa_count);
	write(2, "  sb:  ", 7);
	ft_putnbr_fd2((*principal)->bench->sb_count);
	write(2, "  ss:  ", 7);
	ft_putnbr_fd2((*principal)->bench->ss_count);
	write(2, "  pa:  ", 7);
	ft_putnbr_fd2((*principal)->bench->pa_count);
	write(2, "  pb:  ", 7);
	ft_putnbr_fd2((*principal)->bench->pb_count);
	write(2, "\n", 1);
}

static void	bench_linetwo_funciones(t_principal **principal)
{
	write(2, "[bench] ra:  ", 13);
	ft_putnbr_fd2((*principal)->bench->ra_count);
	write(2, "  rb:  ", 7);
	ft_putnbr_fd2((*principal)->bench->rb_count);
	write(2, "  rr:  ", 7);
	ft_putnbr_fd2((*principal)->bench->rr_count);
	write(2, "  rra:  ", 8);
	ft_putnbr_fd2((*principal)->bench->rra_count);
	write(2, "  rrb:  ", 8);
	ft_putnbr_fd2((*principal)->bench->rrb_count);
	write(2, "  rrr:  ", 8);
	ft_putnbr_fd2((*principal)->bench->rrr_count);
	write(2, "\n", 1);
}

void	bench_union(t_principal **principal)
{
	bench_disorder((*principal)->bench->compute_disorder);
	bench_strategy(principal);
	bench_total_ops(principal);
	bench_lineone_funciones (principal);
	bench_linetwo_funciones (principal);
}
