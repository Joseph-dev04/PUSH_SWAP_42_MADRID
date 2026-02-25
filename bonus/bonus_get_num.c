/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:09:05 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 10:09:05 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static long	ft_atoi_long(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int	duplicate(t_list	**a)
{
	t_list	*n;
	t_list	*move;

	n = *a;
	while (n)
	{
		move = n->next;
		while (move)
		{
			if (n->value == move->value)
				return (0);
			move = move->next;
		}
		n = n->next;
	}
	return (1);
}

int	ft_limit(long limit, char **num)
{
	if (limit > 2147483647 || limit < -2147483648)
	{
		free(*num);
		return (-1);
	}
	return (0);
}

int	ft_itoa_pro(char *str, t_list **a, int index, int *i)
{
	int		j;
	char	*num;
	t_list	*new;
	long	limit;

	j = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (!ft_isdigit(str[j]))
		return (-1);
	while (ft_isdigit(str[j]))
		j++;
	if (str[j] != ' ' && str[j] != '\0')
		return (-1);
	num = ft_substr(str, 0, j);
	limit = ft_atoi_long(num);
	if (ft_limit(limit, &num))
		return (-1);
	*i += j;
	new = ft_new_list(ft_atoi(num), index);
	free(num);
	ft_add_back(a, new);
	return (0);
}

int	ft_get_num(char *list_num, t_list **a)
{
	int		i;
	char	c;

	i = 0;
	while (list_num[i])
	{
		while (list_num[i] == ' ')
			i++;
		if (list_num[i] == '\0')
			break ;
		c = list_num[i];
		if (c >= '\t' && c <= '\r')
			return (ft_error());
		if (ft_isdigit(c) || ((c == '-' || c == '+')
				&& ft_isdigit(list_num[i + 1])))
		{
			if (ft_itoa_pro(&list_num[i], a, 0, &i) == -1)
				return (ft_error());
			if (list_num[i] && list_num[i] != ' ')
				return (ft_error());
		}
		else
			return (ft_error());
	}
	return (0);
}
