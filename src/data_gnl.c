#include "parsing.h"

// char	*gnl_strlcpy(char *dest, char *src, int size)
// {
// 	int		i;

// 	i = 0;
// 	while (src[i] && i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	return (dest);
// }

// int	find_nl(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (-1);
// 	while (str[i])
// 	{
// 		if (str[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// char	*get_rest(char *stat)
// {
// 	int		nl;
// 	int		rest;
// 	char	*new;

// 	nl = find_nl(stat);
// 	rest = ft_strlen(stat) - (nl + 1);
// 	if (nl == -1)
// 		rest = 0;
// 	new = (char *)ft_calloc(rest + 1, sizeof(char));
// 	if (!new)
// 	{
// 		free(stat);
// 		return (NULL);
// 	}
// 	new = gnl_strlcpy(new, stat + nl + 1, rest);
// 	free(stat);
// 	return (new);
// }

// char	*get_line(char *stat)
// {
// 	int		nl;
// 	char	*line;

// 	if (stat[0] == 0)
// 		return (NULL);
// 	nl = find_nl(stat);
// 	if (nl == -1)
// 		nl = ft_strlen(stat) - 1;
// 	line = (char *)ft_calloc(nl + 2, sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	line = gnl_strlcpy(line, stat, nl + 1);
// 	return (line);
// }

// char	*fill_stat(char *stat, int fd)
// {
// 	char	*buf;
// 	char	*tmp;
// 	int		bytes;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buf)
// 		return (NULL);
// 	bytes = 1;
// 	while ((find_nl(stat) == -1) && bytes > 0)
// 	{
// 		bytes = read(fd, buf, BUFFER_SIZE);
// 		if (!bytes)
// 		{
// 			free(buf);
// 			return (stat);
// 		}
// 		tmp = stat;
// 		stat = ft_strjoin(stat, buf);
// 		free(tmp);
// 	}
// 	free(buf);
// 	return (stat);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*stat;

// 	line = "";
// 	if (!stat)
// 	{
// 		stat = ft_calloc(1, sizeof(char));
// 		if (!stat)
// 			return (NULL);
// 	}
// 	stat = fill_stat(stat, fd);
// 	if (!stat)
// 		return (NULL);
// 	line = get_line(stat);
// 	if (!line)
// 	{
// 		free(stat);
// 		return (NULL);
// 	}
// 	stat = get_rest(stat);
// 	return (line);
// }
