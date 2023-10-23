/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:54:05 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/24 16:28:03 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*my_dest;
	char	*my_src;

	my_dest = (char *)dest;
	my_src = (char *)src;
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			my_dest[n] = my_src[n];
	}
	return (dest);
}
