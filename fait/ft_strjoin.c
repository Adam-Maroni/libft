/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:04:00 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/22 22:33:26 by amaroni          ###   ########.fr       */
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

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new_string;
	int		i;
	int		y;

	i = 0;
	if ((new_string =
malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char))) == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		*(new_string + i) = *(s1 + i);
		i++;
	}
	y = 0;
	while (y < ft_strlen(s2))
	{
		*(new_string + i) = *(s2 + y);
		y++;
		i++;
	}
	return (new_string);
}
