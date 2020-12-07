/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:50:52 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/05 22:02:01 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *previous;

	previous = (*lst)->next;
	current = previous->next;
	while (previous)
	{
		ft_lstdelone(previous, (*del));
		previous = current;
		current = current->next;
	}
	(lst) = NULL;
}
