/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:14:29 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/24 17:19:50 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	y;
	char	*first_occurence;

	i = 0;
	y = 0;
	if (!big)
		return (NULL);
	if (!ft_strlen(little) || !(little))
		return (big);
	while ((i <= len) && (i <= ft_strlen(big)))
	{
		if (y == ft_strlen(little))
			return (first_occurence);
		else if (*(big + i) == *(little + y))
		{
			if (y == 0)
				first_occurence = (big + i);
			y++;
		}
		else
			y = 0;
		i++;
	}
	return (NULL);
}
