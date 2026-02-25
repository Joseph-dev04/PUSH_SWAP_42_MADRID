/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:15:54 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/25 13:24:45 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line_bonus.h"

typedef struct s_checker
{
	struct s_list	*a;
	struct s_list	*b;
}	t_checker;

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

void	ft_check_push(char *line, t_checker **bonus);
void	ft_check_reverse(char *line, t_checker **bonus);
void	ft_check_rreverse(char *line, t_checker **bonus);
void	ft_check_swap(char *line, t_checker **bonus);
void	ft_add_back(t_list **lst, t_list *new);
int		ft_size_lis(t_list *a);
t_list	*ft_new_list(int num, int index);
int		ft_strlen2(char *str);
int		ft_isdigit(int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
int		ft_error(void);
int		ft_get_num(char *list_num, t_list **a);
float	compute_disorder(t_list *stack_a);
void	ft_execute(char *line, t_checker **bonus);
int		ft_brench_status(int arc, char **argv, int *position);
int		ft_module_status(int arc, char **argv, int *position);
int		duplicate(t_list	**a);
int		ft_itoa_pro(char *str, t_list **a, int index, int *i);
int		ft_correct(t_checker **bonus);
int		ft_incorrect(t_checker **bonus);
int		ft_clean(t_checker **bonus);
int		charge_num_bonus(int arc, char **argv, t_checker **bonus);
int		ft_space(char *str);
#endif
