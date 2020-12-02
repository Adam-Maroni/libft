/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:41:48 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 13:37:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*rt_pointer;
	int		i;

	i = 0;
	rt_pointer = (void*)malloc(nmemb * size);
	while (i < nmemb)
	{
		*((int*)rt_pointer + i) = 0;
		i++;
	}
	return (rt_pointer);
}
