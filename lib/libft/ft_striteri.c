/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:59:45 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/26 21:09:08 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
changes the original string
s[i] ==> char
s + i => char *
since the original string is being changed, the modification has to be made on 
the address of the original char
*/
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}
