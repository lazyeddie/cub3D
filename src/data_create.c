#include "parsing.h"

char	*ft_strnjoin(char const *s1, char const *s2, int len)
{
	char	*s3;
	int		slen;

	if (!s1 || !s2)
		return (NULL);
	slen = ft_strlen(s1) + len + 1;
	s3 = (char *)malloc(slen * sizeof(char));
	if (s3 == NULL)
		return (0);
	ft_strlcpy(s3, s1, slen);
	ft_strlcat(s3, s2, slen);
	return (s3);
}

void	next_line_mini(int fd, t_data *data)
{
	char	*tmp;
	char	*buf;
	int		res;

	buf = ft_calloc(sizeof(char), READ_SIZE + 1);
	if (!buf)
		exit (1);
	data->input = ft_strdup("");
	res = 1;
	while (res > 0)
	{
		res = read(fd, buf, READ_SIZE);
		tmp = data->input;
		data->input = ft_strnjoin(tmp, buf, res);
		if (!data->input)
		{
			free_ptr(tmp);
			free_ptr(buf);
			exit(1);
		}
		free_ptr(tmp);
	}
	free_ptr(buf);
}

int	is_space(int c)
{
	return (c == 32 || (c >= 8 && c <= 13));
}

int	is_asset(char *input)
{
	// printf("%s\n", input);
	if (!ft_strncmp(input, "NO ", 3))
		return (1);
	if (!ft_strncmp(input, "SO ", 3))
		return (2);
	if (!ft_strncmp(input, "WE ", 3))
		return (3);
	if (!ft_strncmp(input, "EA ", 3))
		return (4);
	if (!ft_strncmp(input, "F ", 2))
		return (5);
	if (!ft_strncmp(input, "C ", 2))
		return (6);
	return (0);	
}

int	sort_data(t_data *data, char *input)
{
	int i;

	i = 0;
	while (input[i] && input[i + 1])
	{
		while (input[i] && is_space(input[i]))
			i++;
		input += i;
		i = 0;
		printf("asset: %d\n", is_asset(input));
		if (input && is_asset(input))
		{
			save_asset(data, input, &i);
			printf("input: %s, i: %d\n", input, i);
		}
		else
		{
			save_map(data, input);
			break ;
		}
	}
	return (0);
}

int	save_asset(t_data *data, char *input, int *i)
{
	int asset;
	int	j;

	j = 0;
	(void)data;
	asset = is_asset(input);
	if (asset >= 1 && asset <= 4)
		*i += 2;
	else if (asset > 4)
		*i += 1;
	while (input[*i] && is_space(input[*i]))
		(*i)++;
	input += *i;
	while (input[j] && !is_space(input[j]))
		j++;
	data->coord[asset - 1] = ft_substr(input, 0, j);
	if (!data->coord[asset - 1])
		exit (1);
	if (input[j] && ft_strncmp(&input[j], "\n", 1))
		(*i)++;
	*i += j;
	return (0);
}

int	save_map(t_data *data, char *input)
{
	data->map = ft_split(input, '\n');
	if (!data->map)
		exit (1);
	return (0);
}

int	data_create(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 3)
		exit(1);
	next_line_mini(fd, data);
	close(fd);
	// check_data(data, data->tools.map);
	sort_data(data, data->input);
	return (0);
}