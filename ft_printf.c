/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:00 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/01 10:54:15 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf4(char const *str, int *i, va_list arg_l, int *total)
{
	if (str[*i + 1] == 'p')
	{
		ft_put_va_ptr(va_arg(arg_l, unsigned long long), total);
	}
	else if (str[*i + 1] == 'u')
	{
		ft_put_va_nbr(va_arg(arg_l, unsigned int), total);
	}
	else if (str[*i + 1] == 'x')
	{
		ft_put_hexa(va_arg(arg_l, long), total);
	}
	else if (str[*i + 1] == 'X')
	{
		ft_put_hexa2(va_arg(arg_l, long), total);
	}
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		ft_put_va_nbr(va_arg(arg_l, int), total);
	}
}

void	ft_printf3(char const *str, int *i, va_list arg_l, int *total)
{
	char	*arg;

	if (str[*i + 1] == 'c')
	{
		ft_putchar_fd(va_arg(arg_l, int), 1);
		*total += 1;
	}
	else if (str[*i + 1] == 's')
	{
		arg = va_arg(arg_l, char *);
		if (!arg)
			arg = "(null)";
		ft_put_va_str(arg, total);
	}
	else if (str[*i + 1] == '%')
	{
		ft_putchar_fd('%', 1);
		*total += 1;
	}
	else
		ft_printf4(str, i, arg_l, total);
	*i += 1;
}

void	ft_printf2(char const *str, int *i, va_list arg_l, int *total)
{
	while (str[++*i])
	{
		if (str[*i] == '%')
		{
			ft_printf3(str, i, arg_l, total);
		}
		else
		{
			ft_putchar_fd(str[*i], 1);
			*total += 1;
		}
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	arg_l;
	int		cont;
	int		*i;
	int		t;
	int		*total;

	cont = -1;
	i = &cont;
	t = 0;
	total = &t;
	va_start(arg_l, str);
	ft_printf2(str, i, arg_l, total);
	va_end(arg_l);
	return (t);
}
