/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:36:15 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/24 21:16:41 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*t;

	t = (char *)s;
	while (n)
	{
		if (*t == (char)c)
			return ((void *)t);
		t++;
		n--;
	}
	return (NULL);
}
