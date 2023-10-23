/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapostol <aapostol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:30:04 by aapostol          #+#    #+#             */
/*   Updated: 2023/01/23 12:11:33 by aapostol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_selector(va_list args, const char *letter);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnum(int n);
int	ft_putuns(unsigned int n);
int	ft_puthex(unsigned long n, const char *letter);
int	ft_putptr(unsigned long ptr);

#endif
