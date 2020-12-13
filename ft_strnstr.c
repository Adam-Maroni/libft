/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:14:29 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/12 20:33:44 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_vars(size_t *i, int *y)
{
	*i = 0;
	*y = 0;
}

char		*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	int		y;
	char	*first_occurence;

	init_vars(&i, &y);
	if (ft_strlen(little) == 0)
		return (big);
	while ((i <= len) && (i <= ft_strlen(big)))
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
