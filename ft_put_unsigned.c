/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:34:14 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/01 12:54:48 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuchar_fd(unsigned int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	lastnum;
	unsigned int	restnum;

	lastnum = n % 10;
	restnum = n / 10;
	if (restnum > 0)
		ft_putunbr_fd(restnum, fd);
	ft_putuchar_fd(lastnum + '0', fd);
}

void	ft_put_va_unbr(unsigned int nbr, int *total)
{
	ft_putunbr_fd(nbr, 1);
	*total += ft_strlen(ft_itoa(nbr));
}
