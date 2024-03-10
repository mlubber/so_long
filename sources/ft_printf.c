/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 11:54:49 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 12:05:34 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static long	countdigits(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_itoa(int n)
{
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l = l * -1;
		size++;
	}
	size = size + countdigits(l);
	ft_putnbr(l);
	return (size);
}

static int	conversions(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	len;
	va_list			arg;

	if (!format)
		return (0);
	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len = len + conversions(format[i], arg);
		}
		else
			len = len + ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
