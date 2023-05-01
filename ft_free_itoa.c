/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:06:16 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/01 17:55:25 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_int_to_char(int n, int i, char *nb, int digits)
{
	if (!nb)
		return (0);
	while (digits > 0)
	{
		nb[digits + i - 2] = (n % 10) + '0';
		n /= 10;
		digits--;
	}
	if (i == 3)
	{
		nb[0] = '-';
		nb[1] = '2';
	}
	else if (i == 2)
		nb[0] = '-';
	return (nb);
}

char	*ft_free_itoa(int n, char *nb, int digits)
{
	int		aux_n;
	int		i;

	if (n == -2147483648)
	{
		aux_n = 147483648;
		i = 3;
	}
	else if (n < 0)
	{
		aux_n = -n;
		i = 2;
	}
	else
	{
		aux_n = n;
		i = 1;
	}
	nb = ft_free_int_to_char(aux_n, i, nb, digits);
	if (!nb)
		return (0);
	nb[ft_count_digits(aux_n) + i - 1] = 0;
	return (nb);
}
