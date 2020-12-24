/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:58:41 by amaroni           #+#    #+#             */
/*   Updated: 2020/12/24 16:19:33 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*int_to_inverted_array(long n)
{
	long	memn;
	int		cp;
	char	*rt;
	char	src[2];

	memn = n;
	cp = 1;
	while ((memn /= 10) > 0)
		cp++;
	memn = n;
	if (!(rt = (char*)malloc((cp + 1) * sizeof(char))))
		return (NULL);
	*rt = '\0';
	while (cp-- > 0)
	{
		src[0] = (char)((memn % 10) + '0');
		src[1] = '\0';
		ft_strlcat(rt, src, ft_strlen(rt) + 2);
		memn /= 10;
	}
	return (rt ? rt : NULL);
}

static char		*invert_array(char *s)
{
	unsigned long		y;
	unsigned long		i;
	char				*invs;

	if (!s)
		return (NULL);
	i = 0;
	y = ft_strlen(s);
	if (!(invs = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (i < ft_strlen(s))
	{
		*(invs + i) = *(s + --y);
		i++;
	}
	invs[i] = '\0';
	free(s);
	return (invs);
}

char			*ft_itoa(int n)
{
	char	*src;
	char	*dst;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n > 0)
	{
		if (invert_array(int_to_inverted_array((long)(n))) == NULL)
			return (NULL);
		return (invert_array(int_to_inverted_array((long)(n))));
	}
	else
	{
		if (!(dst = invert_array(int_to_inverted_array(-(long)(n)))))
			return (NULL);
		if (!(src = (char*)malloc((ft_strlen(dst) + 2) * sizeof(char))))
			return (NULL);
		*src = '-';
		src[1] = '\0';
		ft_strlcat(src, dst, ft_strlen(dst) + 2);
		free(dst);
		return (src);
	}
}
