#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *seur_errores(char *numbers)
{
	int		i;
	int		i_comi;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i] != ' ' || numbers[i] != '"' || numbers[i] < '0' || numbers[i] > '9')
		{
			write(1, "ERROR", 5);
			return (0);
		}
		else
			i++;
	}
	i = 0;
	i_comi = 0;
	while (numbers[i])
		if ( numbers[i] == '"')
			i_comi++;
	if (i_comi % 2 != 0)
	{
		write(1, "ERROR", 5);
		return (0);
	}
	return (1);

}
char *seur_extrem(char *numbers)
{
	char	*line_numbers;
	int		comillas;
	int		i;
	int		j;

	j = 0;
	i = 0;
	comillas = 0;

	if (seur_errores(numbers) == 1)
	{

	while(numbers[i])	//largo cadena malloc, emepezamos con básico, esppacios y números, faltan comprobaciones con doble comilla, un numero entre doble comilla, sino reTurn "ERROR"
	{
		while(numbers[i] == ' ' && numbers[i] == '"')
			i++;
		if (numbers[i] >= '0' && numbers[i] <= '9')
        {
            if (j > 0)
                j++;
            while (numbers[i] >= '0' && numbers[i] <= '9')
            {
                j++;
                i++;
            }
        }
        // else if (numbers[i])
            // i++;
    }
	line_numbers = malloc(sizeof(char) *(j + 1));
	if (!line_numbers)
		return (NULL);

	i = 0;
	j = 0;
	while(numbers[i])	//agregar datos
	{
		while(numbers[i] == ' ')
			i++;
		if (numbers[i] >= '0' && numbers[i] <= '9')
        {
            if (j > 0)
                line_numbers[j++] = ' ';
            
            while (numbers[i] >= '0' && numbers[i] <= '9')
                line_numbers[j++] = numbers[i++];
        }
        else if (numbers[i])
            i++;
    }
    line_numbers[j] = '\0';
    return (line_numbers);
	}
	else
		write(1, "ERROR", 5);


}


int main(void)
{
    char *input = " 8 24       5    10";
    char *result;

    result = seur_extrem(input);

    if (result)
    {
        printf("Entrada: \"%s\"\n", input);
        printf("Resultado: \"%s\"\n", result);
        free(result); // ¡Importante liberar la memoria!
    }
    return (0);
}

//cc seur_extrem.c && ./a.out