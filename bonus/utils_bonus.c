/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 09:48:58 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 12:02:50 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < n && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && (i + j) < n)
			{
				if (needle[j] != haystack[i + j])
					return (NULL);
				j++;
			}
			if (needle[j] == haystack[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	if (needle[0] == 0)
		return ((char *)haystack);
	return (NULL);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (start < len)
	{
		str[start] = s[start];
		start++;
	}
	str[start] = '\0';
	return (str);
}
