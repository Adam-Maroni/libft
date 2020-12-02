/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:23:11 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/02 20:23:13 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *first_element;

	new_list = ft_lstnew((*f)(lst->content));
	first_element = new_list;
	while (lst->next)
	{
		lst = lst->next;
		new_list->next = ft_lstnew((*f)(lst->content));
		new_list = new_list->next;
	}
	new_list = ft_lstnew((*f)(lst->content));
	return (first_element);
}
