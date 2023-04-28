/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:00 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/28 16:43:49 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p2(char const *str, int i, va_list arg_l)
{
	while (str[++i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c')
				ft_putchar_fd(va_arg(arg_l, int), 1);
			else if (str[i + 1] == 's')
				ft_putstr_fd(va_arg(arg_l, char *), 1);
			else if (str[i + 1] == 'p')
				ft_putstr_fd(va_arg(arg_l, char *), 1);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(arg_l, int), 1);
			else if (str[i + 1] == 'u')
				ft_putstr_fd(va_arg(arg_l, char *), 1);
			else if (str[i + 1] == 'x')
				ft_putstr_fd(va_arg(arg_l, char *), 1);
			else if (str[i + 1] == 'X')
				ft_putstr_fd(va_arg(arg_l, char *), 1);
			else if (str[i + 1] == '%')
				ft_putchar_fd('%', 1);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list	arg_l;
	int		i;

	i = -1;
	va_start(arg_l, str);
	ft_p2(str, i, arg_l);
	va_end(arg_l);
	return (0);
}
