#include "push_swap.h"

void	ft_rra(t_list **a)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	plast = *a;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*a = last;
}

void	ft_rrb(t_list **b)
{
	t_list	*first;
	t_list	*plast;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	plast = *b;
	while (plast->next->next)
		plast = plast->next;
	last = plast->next;
	plast->next = NULL;
	last->next = first;
	*b = last;
}

void	ft_rrr(t_list **a, t_list **b)
{
	ft_rra(a);
	ft_rrb(b);
}

void    ft_check_rreverse(char *line, t_checker **bonus)
{
    if (ft_strnstr(line, "rra\n", ft_strlen(line)))
        ft_rra(&(*bonus)->a);
    else if (ft_strnstr(line, "rrb\n", ft_strlen(line)))
        ft_rrb(&(*bonus)->b);
    else if (ft_strnstr(line, "rrr\n", ft_strlen(line)))
        ft_rrr(&(*bonus)->a, &(*bonus)->b);
}