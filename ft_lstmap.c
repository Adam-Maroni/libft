/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Created: 2020/12/01 10:11:01 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 10:51:32 by amaroni          ###   ########.fr       */
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
