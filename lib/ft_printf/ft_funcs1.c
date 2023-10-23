/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:25:32 by aapostol          #+#    #+#             */
/*   Updated: 2023/01/23 11:21:59 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int	ft_putnum(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

static int	countdigits(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putuns(unsigned int n)
{
	int		ret;

	ret = countdigits(n);
	if (n == 0)
		ret += ft_putchar('0');
	else if (n >= 10)
	{
		ft_putuns(n / 10);
		ft_putuns(n % 10);
	}
	else if (n <= 9)
		ret += ft_putchar(n + '0') / 2;
	return (ret);
}
