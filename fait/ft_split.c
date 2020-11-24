/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:03:37 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/24 14:42:12 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_strlen(char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

static int	ft_count_occurence(char *s, char c)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i++ < ft_strlen(s))
	{
		if (*(s + i) == c)
			y++;
	}
	return (y);
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

char		**ft_split(char *s, char c)
{
	int		i;
	int		y;
	char	**rt;
	char	*start;
	char	*scpy;

	rt = (char**)malloc(ft_count_occurence(s, c) * sizeof(char*));
	scpy = (char*)malloc(ft_strlen(s) * sizeof(char));
	ft_strlcpy(scpy, s, ft_strlen(s));
	i = 0;
	while (i++ < ft_strlen(s))
		if (*(scpy + i) == c)
			*(scpy + i) = '\0';
	y = 0;
	i = 0;
	start = scpy;
	while ((i++ < ft_strlen(s)))
		if (*(scpy + i) == '\0')
		{
			rt[y] = (char*)malloc((ft_strlen(start) + 1) * sizeof(char));
			ft_strlcpy(rt[y++], start, ft_strlen(start) + 1);
			start = (scpy + i) + 1;
		}
	rt[y] = "\0";
	return (rt);
}
