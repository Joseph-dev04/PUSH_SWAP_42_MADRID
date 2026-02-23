/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:39:39 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/23 16:07:22 by jopajuel         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap_bonus.h"

int	charge_num(int arc, char **argv, t_checker **bonus)
{
	int	size;
	int	i;

	i = 1;
	while (i < arc)
	{
		size = ft_get_num(argv[i], &(*bonus)->a);
		if (size == -1)
			return (1);
		i++;
	}
	return (0);
}

void	ft_struct(t_checker **bonus)
{
	*bonus = malloc(sizeof(t_checker));
	if (!*bonus)
		return ;
	(*bonus)->a = NULL;
	(*bonus)->b = NULL;
}

void	ft_execute(char *line, t_checker **bonus)
{
	ft_check_swap(line, bonus);
	ft_check_push(line, bonus);
	ft_check_reverse(line, bonus);
	ft_check_rreverse(line, bonus);
}

int	ft_order(t_checker *bonus)
{
	t_list	*temp;
	int		num;

	if (ft_size_lis(bonus->a) == 1)
		return (1);
	else
	{
		temp = bonus->a;
		num = temp->value;
		while (temp->next)
		{
			if (num > temp->next->value)
				return (0);
			temp = temp->next;
			num = temp->value;
		}
	}
	return (1);
}

int	main(int arc, char **argv)
{
	t_checker	*bonus;
	char		*line;

	bonus = NULL;
	if (arc > 1)
	{
		ft_struct(&bonus);
		if (charge_num(arc, argv, &bonus))
			return (ft_clean(&bonus));
		line = get_next_line(0);
		while (line)
		{
			ft_execute(line, &bonus);
			free(line);
			line = get_next_line(0);
		}
		if (ft_order(bonus))
			return (ft_correct(&bonus));
		else
			return (ft_incorrect(&bonus));
	}
	return (ft_error());
}
