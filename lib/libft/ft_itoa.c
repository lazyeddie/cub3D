/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:06:08 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/27 15:30:08 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdigits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	nbr;

	nbr = (long)n;
	nlen = countdigits(nbr);
	str = (char *)malloc(sizeof(char) * nlen + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		*str = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		*str = '0';
	str[nlen] = '\0';
	while (nbr)
	{
		str[--nlen] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
