#include "parsing.h"

// int data_create(t_data *data, char *file)
// {
// 	int		fd;
// 	int		i;
// 	int		file_size = 12;
// 	char	*buf;

// 	data->input = ft_calloc(sizeof(char *), file_size + 1);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 3)
// 		exit (1);
// 	i = 0;
// 	while (i < file_size + 1)
// 	{
// 		buf = get_next_line(fd); // protection (Change exit codes in get next line)
// 		if (buf)
// 		{
// 			data->input[i] = ft_strdup(buf); //protoction
// 			printf("%s", data->input[i]);
// 		}
// 		buf = free_ptr(buf);
// 		i++;
// 	}
// 	return (0);
// }

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
	return (!ft_strncmp(input, "NO ", 3) || \
	!ft_strncmp(input, "SO ", 3) || \
	!ft_strncmp(input, "WE ", 3) || \
	!ft_strncmp(input, "EA ", 3) || \
	!ft_strncmp(input, "F ", 2) || \
	!ft_strncmp(input, "C ", 2));
}

int	sort_data(t_data *data, char *input)
{
	int i;

	i = 0;
	(void)data;
	while(input[i] && input[i + 1])
	{
		while (input[i] && is_space(input[i]))
			i++;
		input += i;
		i = 0;
		if (input && is_asset(input))
		{
			printf("%s\n", input);
			while (input[i] && ft_strncmp(&input[i], "\n", 1))
				i++;
		}
		else
		{
			printf("%s\n", input);
			return (printf("Not found\n"), 1);
		}
	}
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
	// printf("%s\n", data->input);
	// def_map(data, data->tools.map);
	sort_data(data, data->input);
	return (0);
}