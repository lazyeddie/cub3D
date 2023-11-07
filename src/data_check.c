#include "parsing.h"

int	check_data(t_data *data, char *input)
{
	int i;

	i = 0;
	while (input[i] && input[i + 1])
	{
		while (input[i] && is_space(input[i]))
			i++;
		
		i++;
	}
}