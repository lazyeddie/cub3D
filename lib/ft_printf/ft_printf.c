/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:01:17 by aapostol          #+#    #+#             */
/*   Updated: 2023/01/23 11:21:13 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selector(va_list args, const char *letter)
{
	int	ret;

	ret = 0;
	if (*letter == 'c')
		ret += ft_putchar(va_arg(args, int));
	else if (*letter == 's')
		ret += ft_putstr(va_arg(args, char *));
	else if (*letter == 'd' || *letter == 'i')
		ret += ft_putnum(va_arg(args, int));
	else if (*letter == 'u')
		ret += ft_putuns(va_arg(args, unsigned int));
	else if (*letter == 'x' || *letter == 'X')
		ret += ft_puthex(va_arg(args, unsigned int), letter);
	else if (*letter == 'p')
		ret += ft_putptr(va_arg(args, unsigned long));
	else if (*letter == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			ret += ft_putchar(*format);
		else
		{
			ret += ft_selector(args, format + 1);
			format++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}
