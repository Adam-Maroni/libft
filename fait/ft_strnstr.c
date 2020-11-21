/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 18:14:29 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/21 19:27:36 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_strlen(char *s)
{
	unsigned long rt;

	rt = 0;
	while (*(s + rt) != '\0')
		rt++;
	return (rt);
}

char		*ft_strnstr(char *big, char *little, size_t len)
{
	int		i;
	int		y;
	char	*first_occurence;

	i = 0;
	y = 0;
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
			i++;
	}
	return (NULL);
}
