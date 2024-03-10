/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mlubbers <mlubbers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/04 12:02:27 by mlubbers      #+#    #+#                 */
/*   Updated: 2024/03/04 12:03:03 by mlubbers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(long n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10 + '0'));
}
