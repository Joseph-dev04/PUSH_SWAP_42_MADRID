/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:11:24 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/23 13:34:48 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
