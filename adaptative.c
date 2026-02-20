/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:19:36 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 13:56:26 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptative(t_principal **principal)
{
	float	num;

	num = compute_disorder((*principal)->a);
	(*principal)->bench->adaptative = 1;

	if (num >= 0.5f)
	{
		(*principal)->bench->complex = 1;
		ft_radix(principal, ft_size_lis((*principal)->a));
	}
	else if (num < 0.5f && num >= 0.2f)
	{
		(*principal)->bench->medium = 1;
		medium_extraccion(principal);
	}
	else
	{
		(*principal)->bench->simple = 1;
		simple_extraccion(principal);
	}
}
