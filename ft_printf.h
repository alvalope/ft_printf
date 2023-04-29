/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:21:43 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/29 19:56:31 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_put_va_nbr(int nbr, int *total);
void	ft_put_va_str(char *arg, int *total);
void	ft_put_hexa(long arg, int *total);
void	ft_put_hexa2(long arg, int *total);
void	ft_put_va_ptr(unsigned long long arg, int *total);
void	ft_printf4(char const *str, int *i, va_list arg_l, int *total);
void	ft_printf3(char const *str, int *i, va_list arg_l, int *total);
void	ft_printf2(char const *str, int *i, va_list arg_l, int *total);
int		ft_printf(char const *str, ...);

#endif
