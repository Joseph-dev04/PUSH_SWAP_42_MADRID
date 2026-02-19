#include "push_swap.h"

void	ft_rr(t_list **a, t_list **b)
{
    ft_ra(a);
 	ft_rb(b);
}

void	ft_rb(t_list **b)
{
 	t_list	*first;

 	if (!*b || !(*b)->next)
 		return ;
 	first = *b;
 	*b = (*b)->next;
 	first->next = NULL;
 	ft_add_back(b, first);
}

void	ft_ra(t_list **a)
{
 	t_list	*first;

 	if (!*a || !(*a)->next)
 		return ;
 	first = *a;
 	*a = (*a)->next;
 	first->next = NULL;
 	ft_add_back(a, first);
}

void    ft_check_reverse(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "ra\n", ft_strlen(line)))
        ft_ra(&(*bonus)->a);
    else if (ft_strnstr(line, "rb\n", ft_strlen(line)))
        ft_rb(&(*bonus)->b);
    else if (ft_strnstr(line, "rr\n", ft_strlen(line)))
        ft_rr(&(*bonus)->a, &(*bonus)->b);
}