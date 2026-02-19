/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:21:25 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/19 19:04:04 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ((float)mistakes / (float)total_pairs);
	// return (float)((double)mistakes / (double)total_pairs);
}

void ft_putnbr_fd2(int number)
{
	char	c;

	if (number >=10)
		ft_putnbr_fd2(number / 10);
	c = (number % 10) + '0';
	write(2, &c, 1);
}

void bench_disorder(float disorder_value)
{
	int		integro;
	int		decimal;

	integro = disorder_value * 100;
	decimal	= (disorder_value * 10000) % 100;

	write(2, "[bench] Disorder: ", 18);
	ft_putnbr_fd2(integro / 10);
	write(2, ".", 1);
	ft_putnbr_fd2(decimal / 10);
	write(2, "%%\n", 2);
}




void bench_strategy(char strategy, t_principal **principal)
{
	if (strategy == "--simple")
		write(2, "[bench] Strategy: Simple / O2\n", 34);
	else if (strategy == "--medium")
		write(2, "[bench] Strategy: Medium / O(n√n)\n", 44);
	else if (strategy == "--complex")
		write(2, "[bench] Strategy: Complex / O(nlogn)\n", 44);
	else if (strategy == "--adaptative")
	{
		write(2, "[bench] Strategy: Adaptative / ", 34);
		if ((*principal)->bench->strategy == "--simple")
			write(2, "O2\n", 34);
		else if ((*principal)->bench->strategy == "--medium")
			write(2, "O(n√n)\n", 44);
		else if ((*principal)->bench->strategy == "--complex")
			write(2, "O(n log n)\n", 44);
	}
}

void bench_total_ops(t_principal **principal)
{
	int		total_ops;
	char	buffer_total_ops[2147483647];
	int		len;
	
	if (!principal || !*principal || !(*principal)->bench)
		return ;
	total_ops = (*principal)->bench->total_count;
	
	write(2, "[bench] Total_ops: ", 20);
	while(total_ops > 0)
	{
		buffer_total_ops[len++] = (total_ops % 10) + '0';
		total_ops /= 10;
	}
	write(2, buffer_total_ops, ft_strlen(buffer_total_ops));
	write(2, "\n", 1);
}

void bench_lineauno_funciones (t_principal **principal)
{
	
	write(2, "[bench] sa:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->sa_count);
	write(2, "\t", 1);

	
	write(2, "[bench] sb:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->sb_count);
	write(2, "\t", 1);

	
	write(2, "[bench] ss:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->ss_count);
	write(2, "\t", 1);

	
	write(2, "[bench] pa:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->pa_count);
	write(2, "\t", 1);

	
	write(2, "[bench] pb:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->pb_count);
	
	write(2, "\n", 1);

}

void bench_lineados_funciones (t_principal **principal)
{
	
	write(2, "[bench] ra:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->ra_count);
	write(2, "\t", 1);

	
	write(2, "[bench] rb:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->rb_count);
	write(2, "\t", 1);

	
	write(2, "[bench] rr:", 12);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->rr_count);
	write(2, "\t", 1);

	
	write(2, "[bench] rra:", 13);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->rra_count);
	write(2, "\t", 1);

	
	write(2, "[bench] rrb:", 13);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->rrb_count);
	write(2, "\t", 1);

	
	write(2, "[bench] rrr:", 13);
	write(2, "\t", 1);
	ft_putnbr_fd2((*principal)->bench->rrr_count);
	
	write(2, "\n", 1);

}