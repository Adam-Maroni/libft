/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:46:54 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/21 17:48:26 by amaroni          ###   ########.fr       */
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

size_t		ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t rt;

	i = 0;
	y = ft_strlen(dst);
	rt = ft_strlen(dst) + ft_strlen(src);
	while (y < size - 1)
	{
		*(dst + y) = *(src + i);
		y++;
		i++;
	}
	*(dst + y) = '\0';
	return (rt);
}
