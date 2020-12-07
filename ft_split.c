/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:03:37 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/07 17:26:27 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_occurence(char *s, char c)
{
	unsigned long i;
	unsigned long y;

	i = 0;
	y = 0;
	while (i++ < ft_strlen(s))
	{
		if (*(s + i) == c)
			y++;
	}
	return (y);
}

char		**ft_split(char *s, char c)
{
	unsigned long		i;
	unsigned long		y;
	char				**rt;
	char				*start;
	char				*scpy;

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
