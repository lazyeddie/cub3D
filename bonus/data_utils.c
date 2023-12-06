/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:24:42 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 11:50:23 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	is_wall(int c)
{
	return (c == '1' || c == ' ');
}

int	is_abyss(int c)
{
	return (!c || c == ' ');
}

void	skip_a(char *str, int *i, int a)
{
	while (str[*i] && str[*i] == a)
		(*i)++;
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
