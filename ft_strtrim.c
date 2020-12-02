/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:18:24 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 21:54:15 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	loop1(int y, int *i, char *set, char *s1)
{
	while (y < ft_strlen(set))
	{
		while (*(s1 + ++*i) == *(set + y))
			y = 0;
		y++;
	}
}

static void	loop2(int y, int *i, char *set, char *s1)
{
	while (y < ft_strlen(set))
	{
		while (*(s1 + *i) == *(set + y))
		{
			*i -= 1;
			y = 0;
		}
		y++;
	}
}

char		*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		y;
	char	*array;
	char	*start;
	char	*end;

	i = 0;
	y = 0;
	array = (char*)malloc((ft_strlen(s1) + 1) * sizeof(char));
	loop1(y, &i, set, s1);
	start = (s1 + i);
	y = 0;
	i = ft_strlen(s1) - 1;
	loop2(y, &i, set, s1);
	end = (s1 + i);
	i = start - s1;
	y = 0;
	while (i <= (end - s1))
		*(array + y++) = *(s1 + i++);
	return (array);
}
