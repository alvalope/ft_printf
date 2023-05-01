/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:03:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/01 18:46:53 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_va_nbr(int nbr, int *total)
{
	int	digits;
	int	i;

	if (nbr == -2147483648)
	{
		i = 3;
		digits = 9;
	}
	else if (nbr < 0)
	{
		i = 2;
		digits = ft_count_digits(-nbr);
	}
	else
	{
		i = 1;
		digits = ft_count_digits(nbr);
	}
	ft_putnbr_fd(nbr, 1);
	*total += (digits + i - 1);
}

void	ft_put_va_str(char *arg, int *total)
{
	ft_putstr_fd(arg, 1);
	*total += ft_strlen(arg);
}

void	ft_put_hexa(unsigned long long arg, int *total)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (arg < 0)
	{
		ft_put_hexa(arg / 16, total);
	}
	if (arg > 15)
		ft_put_hexa(arg / 16, total);
	ft_putchar_fd(hexa[arg % 16], 1);
	*total += 1;
}

void	ft_put_hexa2(unsigned long long arg, int *total)
{
	char	*hexa2;

	hexa2 = "0123456789ABCDEF";
	if (arg < 0)
	{
		ft_put_hexa2(arg / 16, total);
	}
	if (arg > 15)
		ft_put_hexa2(arg / 16, total);
	ft_putchar_fd(hexa2[arg % 16], 1);
	*total += 1;
}

void	ft_put_va_ptr(unsigned long long arg, int *total)
{
	ft_putstr_fd("0x", 1);
	*total += 2;
	ft_put_hexa(arg, total);
}
