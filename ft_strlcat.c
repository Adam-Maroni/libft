/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:54 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 18:51:04 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t rt;

	i = 0;
	y = ft_strlen(dst);
	rt = ft_strlen(dst) + ft_strlen(src);
	while (y < size)
	{
		*(dst + y) = *(src + i);
		y++;
		i++;
	}
	*(dst + y) = '\0';
	return (rt);
}
