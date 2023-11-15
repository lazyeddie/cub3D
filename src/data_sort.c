#include "parsing.h"

int	transfer_dir(t_data *data, char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	if (not_valid_file(str, ".xpm", 4))
		return (FILE_ERR);
	tmp = ft_strdup(str);
	if (!tmp)
		return (MALLOC_ERR);
	if (i == 0)
		data->north = tmp;
	else if (i == 1)
		data->south = tmp;
	else if (i == 2)
		data->west = tmp;
	else if (i == 3)
		data->east = tmp;
	return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ',')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	transfer_col(char *str, int *color, int j)
{
	int		ret;

	while (j < 3)
	{
		ret = 0;
		if (check_number(str))
			return (1);
		while (ft_isdigit(*str))
		{
			ret = ret * 10 + (*str - '0');
			str++;
		}
		if (ret >= 0 && ret < 255)
			color[j] = ret;
		else
			return (1);
		if (*str == ',')
			str++;
		else if (j < 2)
			return (1);
		j++;
	}
	return (0);
}

int	transfer_assets(t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i <= 5)
	{
		if (data->assarr[i] && i <= 3)
		{
			// ret = open(data->assarr[i], O_RDONLY);
			// if (ret < 0)
			// 	return (ASSET_ERR);
			// close(ret);
			if (transfer_dir(data, data->assarr[i], i))
				return (MALLOC_ERR);
		}
		ret = 0;
		if (data->assarr[i] && i == 4)
			ret = transfer_col(data->assarr[i], data->floor, 0);
		if (data->assarr[i] && i == 5)
			ret = transfer_col(data->assarr[i], data->ceiling, 0);
		if (ret)
			return (RGB_ERR);
		i++;
	}
	return (0);
}

int	sort_data(t_data *data)
{
	int	ret;

	ret = 0;
	ret = transfer_assets(data);
	if (ret)
		return (ret);
	ret = map_check_quali(data->map);
	return (ret);
}
