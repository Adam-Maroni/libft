/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 10:43:27 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/22 10:55:10 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_strlen(char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t y;
	size_t rt;

	y = 0;
	rt = ft_strlen(src);
	while (y < size - 1)
	{
		*(dst + y) = *(src + y);
		y++;
	}
	*(dst + y) = '\0';
	return (rt);
}
