/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:09:11 by aapostol          #+#    #+#             */
/*   Updated: 2022/10/03 18:27:48 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 55;
	int	b = 13;

	printf("%d\n", ft_isdigit(a));
	printf("%d\n", ft_isdigit(b));
}
*/
