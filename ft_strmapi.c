/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:55:18 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 10:55:39 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlen(char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

char			*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rt;

	i = 0;
	if ((rt = (char*)malloc(ft_strlen(s) * sizeof(char))) == NULL)
		return (NULL);
	while (s[i])
	{
		rt[i] = f(i, s[i]);
		i++;
	}
	return (rt);
}
