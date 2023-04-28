/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:41:43 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/24 15:58:54 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	lastnum;
	int	restnum;

	if (n < 0)
	{
		ft_putchar(fd, '-');
		if (n == -2147483648)
		{
			ft_putchar(fd, '2');
			n = 147483648;
			ft_putnbr_fd(n, fd);
		}
		else
			ft_putnbr_fd(-n, fd);
	}
	else
	{
		lastnum = n % 10;
		restnum = n / 10;
		if (restnum > 0)
			ft_putnbr_fd(restnum, fd);
		ft_putchar(fd, lastnum + '0');
	}
}
