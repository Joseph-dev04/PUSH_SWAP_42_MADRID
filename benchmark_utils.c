/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:21:25 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/20 19:03:50 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd2(int number)
{
	char	c;
	
	if (number >= 10)
		ft_putnbr_fd2(number / 10);
	c = (number % 10) + '0';
	write(2, &c, 1);
}

void	bench_disorder(float disorder_value)
{
	int		integro;
	int		decimal;

	integro = (disorder_value * 100);
	decimal = ((disorder_value * 10000) - (integro * 100));
	write(2, "[bench] Disorder: ", 18);
	ft_putnbr_fd2(integro);
	write(2, ".", 1);
	ft_putnbr_fd2(decimal);
	if (decimal < 10)
		write(2, "0", 1);
	write(2, "%\n", 2);
}
