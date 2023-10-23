/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:23:13 by aapostol          #+#    #+#             */
/*   Updated: 2023/04/12 16:39:03 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_array(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	return (NULL);
}

static void	*copywords(char **array, char const *str, char sep)
{
	char const	*word;
	size_t		i;

	i = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		word = str;
		while (*word && *word != sep)
			word++;
		if (*word == sep || (!*word && word > str))
		{
			array[i] = ft_substr(str, 0, word - str);
			if (!array[i])
				return (clear_array(array, i));
			str = word;
			if (*word)
				str++;
			i++;
		}
	}
	array[i] = NULL;
	return ((void *)str);
}

static int	wordcount(char const *str, char sep)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (*str)
			wc++;
		while (*str && *str != sep)
			str++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**sentence;
	int		wc;

	wc = wordcount(s, c);
	sentence = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!sentence)
		return (NULL);
	if (!copywords(sentence, s, c))
	{
		free(sentence);
		return (NULL);
	}
	return (sentence);
}

/*
int	main(void)
{
	char *str = "hello!";
	char **result = ft_split(str, ' ');
	free(result);
	return (0);
}*/
