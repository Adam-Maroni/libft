/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:34:26 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 13:41:34 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while ((i < n) && *((char*)src + i) != c)
	{
		*((char*)dest + i) = *((char*)src + i);
		i++;
	}
	if (*((char*)src + i) == c)
	{
		*((char*)dest + i) = *((char*)src + i);
		return (dest + (i + 1));
	}
	else
		return (NULL);
}
