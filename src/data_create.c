#include "parsing.h"

int data_create(t_data *data, char *file)
{
	int		fd;
	int		i;
	int		file_size = 12;
	char	*buf;

	data->input = ft_calloc(sizeof(char *),file_size);
	fd = open(file, O_RDONLY);
	if (fd < 3)
		exit (1);
	i = 0;
	while (i < file_size + 1)
	{
		buf = get_next_line(fd); // protection (Change exit codes in get next line)
		if (buf)
		{
			data->input[i] = ft_strdup(buf); //protoction
			printf("%s", data->input[i]);
		}
		buf = free_ptr(buf);
		i++;
	}
	return (0);
}