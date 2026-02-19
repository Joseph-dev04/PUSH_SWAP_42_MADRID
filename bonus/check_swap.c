#include "push_swap.h"

void	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!*a || !(*a)->next)
		return ;
	first =  *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	ft_sb(t_list **b)
{
	t_list	*first;
	t_list	*second;

	if (!*b || !(*b)->next)
		return ;
	first =  *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void    ft_check_swap(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "sa\n", ft_strlen(line)))
        ft_sa(&(*bonus)->a);
    else if (ft_strnstr(line, "sb\n", ft_strlen(line)))
        ft_sb(&(*bonus)->b);
    else if (ft_strnstr(line, "ss\n", ft_strlen(line)))
        ft_ss(&(*bonus)->a, &(*bonus)->b);
}