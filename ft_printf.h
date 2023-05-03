/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:21:43 by alvalope          #+#    #+#             */
/*   Updated: 2023/05/03 17:29:04 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	ft_put_va_nbr(int nbr, size_t *total);
void	ft_put_va_str(char *arg, size_t *total);
void	ft_put_hexa(unsigned long long arg, size_t *total);
void	ft_put_hexa2(unsigned long long arg, size_t *total);
void	ft_put_va_ptr(unsigned long long arg, size_t *total);
int		ft_putuchar_fd(unsigned int c, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_put_va_unbr(unsigned int nbr, size_t *total);
int		ft_count_digits2(int n);
char	*ft_free_int_to_char(int n, int i, char *nb, int digits);
char	*ft_free_itoa(int n, char *nb, int digits);
int		ft_strlen2(char *str);
void	ft_printf4(const char *str, int *i, va_list *arg_l, size_t *total);
void	ft_printf3(const char *str, int *i, va_list *arg_l, size_t *total);
void	ft_printf2(const char *str, int *i, va_list *arg_l, size_t *total);
int		ft_printf(const char *str, ...);

#endif
