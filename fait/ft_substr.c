/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:38:13 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/22 21:59:49 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	i = 0;
	new_string = (char*)malloc(len * sizeof(char));
	while (i < len)
	{
		*(new_string + i) = *(s + i + start);
		i++;
	}
	return (new_string);
}
