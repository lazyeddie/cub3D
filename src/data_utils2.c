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
