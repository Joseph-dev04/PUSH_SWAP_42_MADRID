#include "push_swap.h"

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void    ft_check_push(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "pa\n", ft_strlen(line)))
        ft_pa(&(*bonus)->a, &(*bonus)->b);
    else if (ft_strnstr(line, "pb\n", ft_strlen(line)))
        ft_pb(&(*bonus)->a, &(*bonus)->b);
}