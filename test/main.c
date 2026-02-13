void	ft_logic(int **list, int inicio, int final)
{
	int	i;
	int	j;
	int	pivote;
	int	aux;

	i = inicio;
	j = final;
	pivote = (*list)[(inicio + final) / 2];
	while (i <= j)
	{
		while ((*list)[i] < pivote)
			i++;
		while ((*list)[j] > pivote)
			j--;
		if (i <= j)
		{
			aux = (*list)[i];
			(*list)[i] = (*list)[j];
			(*list)[j] = aux;
			i++;
			j--;
		}
	}
	if (inicio < j)
		ft_logic(list, inicio, j);
	if (final > i)
		ft_logic(list, i, final);
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int	*num;
	num = malloc(sizeof(int) * 500);
	int i = 500;
	int j = 0;
	while(i > 0)
	{
		num[j] = i;
		j++;
		i--;
	}
	ft_logic(&num, 0, 500);
	i = 0;
	while(i < 500)
	{
		printf("%i ", num[i]);
		i++;
	}
	
	return 0;
}