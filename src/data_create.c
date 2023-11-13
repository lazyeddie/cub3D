#include "parsing.h"
#include <errno.h>

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

int	next_line_mini(int fd, t_data *data)
{
	char	*tmp;
	char	*buf;
	int		res;

	buf = ft_calloc(sizeof(char), READ_SIZE + 1);
	if (!buf)
		return (1);
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
			return (1);
		}
		free_ptr(tmp);
	}
	free_ptr(buf);
	return (0);
}

int	is_space(int c)
{
	return (c == 32 || (c >= 8 && c <= 13));
}

int	is_asset(char *input)
{
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

int	extract_data(t_data *data, char *input)
{
	int	i;

	i = 0;
	while (input[i] && input[i + 1])
	{
		while (input[i] && input[i] == 10)
			i++;
		input += i;
		i = 0;
		if (input && is_asset(input))
		{
			if (save_asset(data, input, &i))
				return (1);
		}
		else
		{
			if (save_map(data, input))
				return (1);
			break ;
		}
	}
	return (0);
}

int	save_asset(t_data *data, char *input, int *i)
{
	int	asset;
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
	data->assarr[asset - 1] = ft_substr(input, 0, j);
	if (!data->assarr[asset - 1])
		return (1);
	if (input[j] && ft_strncmp(&input[j], "\n", 1))
		j++;
	*i += j;
	return (0);
}

int	save_map(t_data *data, char *input)
{
	data->map = ft_split(input, '\n');
	if (!data->map)
		return (1);
	return (0);
}

char	*ft_strerror(int ret)
{
	static const char	*errs[] = {
		"General Error.",
		"Parsing Error: File not valid.",
		"Parsing Error: Empty file.",
		"Parsing Error: Duplicate Found.",
		"Parsing Error: Invalid input in file. (Check for tabs)",
		"Parsing Error: Map has invalid characters.",
		"Invalid Asset: No such file or directory.",
		"Malloc Error: Unable to allocate memory buffer.",
		"Parsing Error: Invalid RGB colors.",
		"Map Error: Invalid Map - Lonely Spaces.",
		"Map Error: Invalid Map - Walls Missing.",
	};

	return ((char *)errs[ret]);
}

int	not_valid_file(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	while (n--)
	{
		if (s1[--i] != s2[n])
			return (s1[i] - s2[n]);
	}
	return (0);
}

int	parsing(t_game *game, t_data *data, char *file)
{
	int	fd;
	int	ret;

	if (not_valid_file(file, ".cub", 4))
		free_game(game, ft_strerror(FILE_ERR));
	fd = open(file, O_RDONLY);
	if (fd < 3)
		free_game(game, strerror(errno));
	ret = next_line_mini(fd, data);
	close(fd);
	if (ret)
		free_game(game, ft_strerror(MALLOC_ERR));
	ret = check_data(data, data->input);
	if (ret)
		free_game(game, ft_strerror(ret));
	if (extract_data(data, data->input))
		free_game(game, ft_strerror(MALLOC_ERR));
	ret = sort_data(data);
	if (ret)
		free_game(game, ft_strerror(ret));
	return (0);
}
