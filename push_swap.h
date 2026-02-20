/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopajuel <jopajuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:29:24 by jopajuel          #+#    #+#             */
/*   Updated: 2026/02/20 12:41:29 by jopajuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> //para fd

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stats
{
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
	int			pa_count;
	int			pb_count;
	int			sa_count;
	int			sb_count;
	int			ss_count;
	int			total_count;
	int			simple;
	int			medium;
	int			complex;
	int			adaptative;
}	t_stats;

typedef struct s_principal
{
	struct s_stats	*bench;
	struct s_list	*a;
	struct s_list	*b;
}	t_principal;





int		ft_get_num(char *list_num, t_list **a);
int		ft_strlen(char *str);
void	ft_type(char **argv, int arc, t_principal **principal, int flag);
int		ft_error();
void	ft_free(t_list *a);
void	ft_free_a(t_list *a);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_new_list(int num, int index);
int		ft_atoi(const char *str);
void	ft_add_back(t_list **lst, t_list *new);

void	ft_sb(t_principal **principal, int bench);
void	ft_sa(t_principal **principal, int bench);
void	ft_ss(t_principal **principal);

void	ft_rb(t_principal **principal, int bench);
void	ft_ra(t_principal **principal, int bench);
void	ft_rr(t_principal **principal);

void	ft_pa(t_principal **principal, int count_bench);
void	ft_pb(t_principal **principal, int count_bench);

void	ft_rrb(t_principal **principal, int count_bench);
void	ft_rra(t_principal **principal, int count_bench);
void	ft_rrr(t_principal **principal);

float	compute_disorder(t_list *stack_a);

void	ft_radix(t_principal **principal, int size);
void	*ft_quicksort(t_list **a);
int		num_len(int nb);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
int		ft_size_lis(t_list *a);

void	simple_extraccion(t_principal **principal);
void	medium_extraccion(t_principal **principal);

int		ft_brench_status(int arc, char **argv, int *position);
int		ft_module_status(int arc, char **argv, int *position);
void	ft_adaptative(t_principal **principal);

//--medium
void	ft_reset_index(t_list **a);

//--medium && --simple
void simple_extraccion_pequena(t_principal **principal);

#endif
