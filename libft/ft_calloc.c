/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:44:39 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/19 19:15:44 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	p = ptr;
	i = 0;
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return (ptr);
}
