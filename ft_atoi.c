/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:24:04 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/02 14:20:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	return_rt_value(int i, char **array)
{
	long x10;
	long rt;

	x10 = 1;
	rt = 0;
	while (--i >= 0)
	{
		rt += ((*array)[i] - '0') * (x10);
		x10 *= 10;
	}
	return (rt);
}

static void	initialize_variables(int *sign, int *i, long *rt, long *x10)
{
	*sign = 1;
	*i = 0;
	*rt = 0;
	*x10 = 1;
}

int			ft_atoi(char *nptr)
{
	int			i;
	char		*array;
	long		rt;
	int			sign;
	long		x10;

	initialize_variables(&sign, &i, &rt, &x10);
	if ((nptr[0] == '+') || (nptr[0] == '-') || (nptr[0] == ' '))
	{
		if (nptr[0] == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(nptr[i]) > 0)
		i++;
	if ((array = (char*)calloc(i + 1, sizeof(char))) == NULL)
		return (0);
	i = 0;
	while (ft_isdigit(nptr[i]) > 0)
	{
		array[i] = nptr[i];
		i++;
	}
	rt = return_rt_value(i, &array);
	return (rt * sign);
}
