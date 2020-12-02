/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:40:35 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/18 18:15:29 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, int n)
{
	int i;

	if (n == 0)
		return (0);
	i = 0;
	while ((*((char*)s1 + i) == *((char*)s2 + i)) && (i < n))
		i++;
	if ((i < n) && (*((char*)s1 + i) > *((char*)s2 + i)))
		return (1);
	else if ((i < n) && (*((char*)s1 + i) == *((char*)s2 + i)))
		return (0);
	else if ((i < n) && (*((char*)s1 + i) < *((char*)s2 + i)))
		return (-1);
	else
		return (0);
}
