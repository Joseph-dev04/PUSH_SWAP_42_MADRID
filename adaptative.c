/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:19:36 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/19 10:01:26 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptative(t_principal **principal)
{
	float	num;

	num = compute_disorder((*principal)->a);
	//printf("%f\n", num);
	if (num >= 0.5f)
		ft_radix(principal, ft_size_lis((*principal)->a));
	else if (num < 0.5f && num >= 0.2f)
		medium_extraccion(principal);
	else
		simple_extraccion(principal);
}
