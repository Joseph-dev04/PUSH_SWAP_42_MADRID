/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:11:24 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/23 17:02:05 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_index(t_list **a)
{
	t_list	*nodo_a;

	nodo_a = *a;
	while (nodo_a)
	{
		nodo_a->index = -1;
		nodo_a = nodo_a->next;
	}
}
