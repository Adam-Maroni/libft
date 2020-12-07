/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:34:26 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/04 10:40:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while ((i < n) && *((unsigned char*)src + i) != (unsigned char)c)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)src + i);
		i++;
	}
	if (*((unsigned char*)src + i) == (unsigned char)c)
	{
		*((unsigned char*)dest + i) = *((unsigned char*)src + i);
		return (dest + (i + 1));
	}
	else
		return (NULL);
}
