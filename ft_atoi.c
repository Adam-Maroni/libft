/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:24:04 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 18:52:14 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char *nptr)
{
	int		i;
	int		rt;
	int		x10;
	char	*array;

	i = 0;
	rt = 0;
	x10 = 1;
	while (ft_isdigit(*(nptr + i)) > 0)
		i++;
	if (i == 0)
		return (0);
	array = (char*)ft_calloc((i + 1), sizeof(char));
	while (--i >= 0)
		*(array + (i)) = *(nptr + (i));
	i = ft_strlen(array);
	while (i > 0)
	{
		rt += ((*(array + (i - 1)) - '0') * (x10));
		x10 *= 10;
		i--;
	}
	free(array);
	return (rt);
}
