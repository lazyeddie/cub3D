#include "parsing.h"

int	check_data(t_data *data, char *input)
{
	int i;
	int asset;

	i = 0;
	while (input[i] && input[i + 1])
	{
		while (input[i] && is_space(input[i]))
			i++;
		input += i;
		i = 0;
		if (input && is_asset(input))
		{
			while (input[i] && !is_space(input[i]))
				i++;
			while (input[i] && is_space(input[i]))
				i++;

		}
		i++;
	}
}