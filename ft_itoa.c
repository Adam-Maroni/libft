/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:41 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/01 19:45:32 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*int_to_inverted_array(long n)
{
	long	memn;
	int		cp;
	char	*rt;
	char	*src;

	memn = n;
	cp = 1;
	while ((memn /= 10) > 0)
		cp++;
	memn = n;
	if ((rt = (char*)malloc(cp * sizeof(char))) == NULL)
		return (NULL);
	while (cp-- > 0)
	{
		src = (char*)malloc(sizeof(char));
		*src = (char)((memn % 10) + '0');
		ft_strlcat(rt, src, ft_strlen(rt) + 1);
		memn /= 10;
		free(src);
	}
	return (rt);
}

static char		*invert_array(char *s)
{
	int		y;
	int		i;
	char	*invs;

	i = 0;
	y = ft_strlen(s);
	invs = (char*)malloc(ft_strlen(s) * sizeof(char));
	while (i < ft_strlen(s))
	{
		*(invs + i) = *(s + --y);
		i++;
	}
	return (invs);
}

char			*ft_itoa(int n)
{
	long	new_n;
	char	*src;
	char	*dst;

	if (n == 0)
		return ("0");
	else if (n > 0)
	{
		new_n = n;
		return (invert_array(int_to_inverted_array(new_n)));
	}
	else
	{
		new_n = -n;
		dst = invert_array(int_to_inverted_array(new_n));
		src = (char*)malloc(ft_strlen(dst) * sizeof(char));
		*src = '-';
		ft_strlcat(src, dst, ft_strlen(dst) + 1);
		return (src);
	}
}
