/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:39:39 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/19 12:40:54 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	charge_num(char **argv, t_checker **bonus)
{
	int	size;

	//printf("%i\n",arc);
	//printf("entro %i\n", i);
	size = ft_get_num(argv[1], &(*bonus)->a);
	if (size == -1)
		return (1);
	return (0);
}

void	ft_struct(t_checker **bonus)
{
	*bonus = malloc(sizeof(t_checker));
	if (!*bonus)
		return (NULL);
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

int	main(int arc, char **argv)
{
	t_checker	*bonus;
	char		*line;

	bonus = NULL;
	if (arc == 2)
	{
		ft_struct(&bonus);
		if (!charge_num(argv, &bonus))
			return (ft_error());
		line = get_next_line(1);
		while (line)
		{
			ft_execute(line, &bonus);
			free(line);
			line = get_next_line(1);
		}
		if (ft_orden())
			return (write(1, "OK\n", 3));
	}
	return (ft_error());
}

