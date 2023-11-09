#include "parsing.h"

void	skip_word(char *str, int *i, bool word)
{
	if (word)
	{
		while (str[*i] && !is_space(str[*i]))
			(*i)++;
	}
	else
	{
		while (str[*i] && is_space(str[*i]))
			(*i)++;
	}
}

void	skip_a(char *str, int *i, int a)
{
	while (str[*i] && str[*i] == a)
		(*i)++;
}

int	check_counter(int *count)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		if (count[i] != 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_asset(t_data *data, char *input, int *i)
{
	int	asset;

	asset = is_asset(input);
	if (input && asset)
	{
		if (data->count[asset - 1] == 1)
			return (DUP_ERR);
		else
			data->count[asset - 1] = 1;
		skip_word(input, i, true);
		skip_a(input, i, ' ');
		skip_word(input, i, true);
	}
	else if (input && !asset && input[*i] != '\n')
		return (INPUT_ERR);
	return (0);
}

int	check_map(char c, int *count)
{
	if (c == 32 || c == 10 || c == 48 || c == 49)
		return (0);
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && *count == 0)
	{
		*count = 1;
		return (0);
	}
	else
		return (1);
}

int	check_data(t_data *data, char *input)
{
	int	i;
	int	ret;
	int	count;

	i = 0;
	count = 0;
	if (input[i] == '\0')
		return (EMPTY_ERR);
	while (input[i])
	{
		skip_a(input, &i, '\n');
		input += i;
		i = 0;
		if (check_counter(data->count))
		{
			ret = check_asset(data, input, &i);
			if (ret)
				return (ret);
		}
		else if (check_map(input[i], &count))
			return (MAP_CHAR_ERR);
		i++;
	}
	return (0);
}
