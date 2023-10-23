/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:05:48 by aapostol          #+#    #+#             */
/*   Updated: 2022/11/02 14:33:31 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit;

	lit = ft_strlen(little);
	if (lit == 0)
		return ((char *)big);
	while (*big && lit <= len)
	{
		if (ft_strncmp(big, little, lit) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
