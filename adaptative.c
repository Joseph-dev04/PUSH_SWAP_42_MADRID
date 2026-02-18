#include "push_swap.h"

void    ft_adaptative(t_principal **principal)
{
    float num = compute_disorder((*principal)->a);
    if (num >= 0.5f)
        ft_radix(principal, ft_size_lis((*principal)->a));
    else if (num < 0.5f && num >= 0.2f)
        medium_extraccion(principal);
    else
        simple_extraccion(principal);
}