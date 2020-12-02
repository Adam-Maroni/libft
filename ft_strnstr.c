/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:14:29 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/02 16:53:51 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(int *i, int *y)
{
	*i = 0;
	*y = 0;
}

char		*ft_strnstr(char *big, char *little, size_t len)
{
	int		i;
	int		y;
	char	*first_occurence;

	init_vars(&i, &y);
	if (ft_strlen(little) == 0)
		return (big);
	while (i <= (int)len)
	{
		if (y == (int)ft_strlen(little))
			return (first_occurence);
		else if (*(big + i) == *(little + y))
		{
			if (y == 0)
				first_occurence = (big + i);
			i++;
			y++;
		}
		else
		{
			i++;
			y = 0;
		}
	}
	return (NULL);
}
