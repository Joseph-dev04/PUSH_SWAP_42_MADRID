/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:36:21 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/10 12:32:12 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_itoa_pro(char **str, t_list **a, int index)
{
	int		i;
	char	*num;
	t_list	*new;

	i = 0;
	while (ft_isdigit((*str)[i]))
		i++;
	num = ft_substr(*str, 0, i);
	*str = *str + i;
	new = ft_new_list(ft_atoi(num), index);
	free(num);
	ft_add_back(a, new);
}

// "    123  "
int	ft_get_num(char *list_num, t_list **a)
{
	int	index;

	index = 0;
	while (*list_num)
	{
		if (*list_num >= '\t' && *list_num <= '\r')
		{//printf("%c\n", *list_num);
			return (ft_error());
		}
		if (*list_num != ' ' && !ft_isdigit(*list_num))
		{//printf("%c\n", *list_num);
			return (ft_error());
		}
		if (*list_num >= '0' && *list_num <= '9')
		{//printf("%i\n", index);
			ft_itoa_pro(&list_num, a, index);
		}
		if (*list_num)
			list_num++;
		index++;
	}
	return (index);
}
