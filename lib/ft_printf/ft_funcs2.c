/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <rpinchas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:39:50 by aapostol          #+#    #+#             */
/*   Updated: 2023/12/06 12:59:58 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counthex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned long n, const char *letter)
{
	int	hexlen;

	hexlen = counthex(n);
	if (n == 0)
		ft_putchar('0');
	else
	{
		if (n >= 16)
		{
			ft_puthex(n / 16, letter);
			ft_puthex(n % 16, letter);
		}
		else if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (*letter == 'x')
				ft_putchar(n + 'a' - 10);
			else if (*letter == 'X')
				ft_putchar(n + 'A' - 10);
		}
	}
	return (hexlen);
}

int	ft_putptr(unsigned long ptr)
{
	int	ptrlen;

	if (ptr == 0)
	{
		ptrlen = ft_putstr("(nil)");
		return (ptrlen);
	}
	ptrlen = ft_putstr("0x");
	ptrlen += ft_puthex(ptr, "x");
	return (ptrlen);
}
