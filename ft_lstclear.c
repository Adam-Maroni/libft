/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:50:52 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 00:01:09 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *previous;

	current = (*lst)->next;
	while (current->next)
	{
		previous = current;
		current = current->next;
		(*del)(previous);
		free(previous);
	}
	(*del)(current);
	free(current);
	(*lst)->next = NULL;
}
