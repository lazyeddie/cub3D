#include "parsing.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_wall(int c)
{
	return (c == '1' || c == ' ');
}

int	is_abyss(int c)
{
	return (!c || c == ' ');
}

void	skip_a(char *str, int *i, int a)
{
	while (str[*i] && str[*i] == a)
		(*i)++;
}
