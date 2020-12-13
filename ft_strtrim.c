/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:18:24 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/13 16:58:46 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	isfound_fromfront(char *s2, char *start)
{
	unsigned long i;

	i = 0;
	while ((s2[i] != *start) && (i < ft_strlen(s2)))
		i++;
	if (i >= ft_strlen(s2))
		return (1);
	else
		return (0);
}

static int	isfound_fromback(char *s2, char *end)
{
	unsigned long i;

	i = 0;
	while ((i < ft_strlen(s2)) && (s2[i] != *end))
		i++;
	if (i >= ft_strlen(s2))
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char *s1, char *s2)
{
	char *start;
	char *end;

	start = s1;
	end = s1 + (ft_strlen(s1) - 1);
	while (start < end && !isfound_fromfront(s2, start))
		start++;
	while (start < end && !isfound_fromback(s2, end))
		end--;
	if (end > start)
		return (ft_substr(s1, (unsigned int)(start - s1),
					(unsigned int)(end - start + 1)));
	else
		return ("");
}
