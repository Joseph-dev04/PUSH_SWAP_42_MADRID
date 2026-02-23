/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:12:36 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 16:12:39 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap_bonus.h"

int	ft_clean(t_checker **bonus)
{
	t_list	*temp;

	while ((*bonus)->a)
	{
		temp = (*bonus)->a;
		(*bonus)->a = (*bonus)->a->next;
		free(temp);
	}
	free((*bonus));
	return (1);
}

int	ft_error(void)
{
	write (2, "Error\n", 6);
	return (-1);
}

int	ft_correct(t_checker **bonus)
{
	t_list	*temp;

	while ((*bonus)->a)
	{
		temp = (*bonus)->a;
		(*bonus)->a = (*bonus)->a->next;
		free(temp);
	}
	free((*bonus)->b);
	free(*bonus);
	write (1, "OK\n", 3);
	return (0);
}

int	ft_incorrect(t_checker **bonus)
{
	t_list	*temp;

	while ((*bonus)->a)
	{
		temp = (*bonus)->a;
		(*bonus)->a = (*bonus)->a->next;
		free(temp);
	}
	free((*bonus)->b);
	free(*bonus);
	write (1, "KO\n", 3);
	return (1);
}
