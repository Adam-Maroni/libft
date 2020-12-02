/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:19:02 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/18 16:19:12 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*rt_pointer;
	int		i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	if (i > 0)
	{
		rt_pointer = (char*)malloc(sizeof(char) * i);
		i = 0;
		while (*(s + i) != '\0')
		{
			*(rt_pointer + i) = *(s + i);
			i++;
		}
		*(rt_pointer + i + 1) = '\0';
	}
	else
		return (NULL);
	return (rt_pointer);
}
