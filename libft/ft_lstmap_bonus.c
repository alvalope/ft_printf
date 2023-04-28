/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:57 by alvalope          #+#    #+#             */
/*   Updated: 2023/04/27 21:31:16 by alvalope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;

	if (!lst)
		return (0);
	new_l = malloc(sizeof(t_list));
	if (!new_l)
		return (0);
	new_l->content = f(lst->content);
	if (lst->next)
		new_l->next = ft_lstmap(lst->next, f, del);
	else
		new_l->next = 0;
	return (new_l);
}
