/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:29:24 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/13 10:10:04 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

int		ft_get_num(char *list_num, t_list **a);
int	ft_strlen(char *str);
void	ft_type_algotim(char **argv);
int		ft_error();
void	ft_free(t_list *a);
void	ft_free_a(t_list *a);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_new_list(int num, int index);
int		ft_atoi(const char *str);
void 	ft_add_back(t_list **lst, t_list *new);

void	ft_sb(t_list **b);
void	ft_sa(t_list **a);
void	ft_ss(t_list **a, t_list **b);

void    ft_rr(t_list **a, t_list **b);
void    ft_rb(t_list **b);
void    ft_ra(t_list **a);

void    ft_pa(t_list **a, t_list **b);
void    ft_pb(t_list **a, t_list **b);

static int comprobar_duplicados(t_list **a);
float compute_disorder(t_list *stack_a);

void	ft_radix(t_list **a, t_list **b);
int	num_len(int nb);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int	ft_size_lis(t_list *a);

void simple_extraccion(t_list **a, t_list **b);
#endif
