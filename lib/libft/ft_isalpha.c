/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:43:00 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/03 18:54:27 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 65;
	int	b = 3;

	printf("%d\n", ft_isalpha(a));
	printf("%d\n", ft_isalpha(b));
}
*/
