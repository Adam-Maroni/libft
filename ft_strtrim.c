/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:18:24 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/23 15:38:09 by amaroni          ###   ########.fr       */
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

char	*ft_strtrim(char *s1, char *set)
{
	int i;
	int y;
	char *array;
	char *start;
	char *end;

	i = 0;
	y = 0;
	array = (char*)malloc((strlen(s1) + 1) * sizeof(char));
	while (y < ft_strlen(set))
	{
		while (*(s1 + i) == *(set + y))
		{
			i++;
			y = 0;
		}
		y++;
	}
	start = (s1 + i);
	y = 0;
	i = ft_strlen(s1) - 1;
	while (y < ft_strlen(set))
	{
		while (*(s1 + i) == *(set + y))
		{
			i--;
			y = 0;
		}
		y++;
	}
	end = (s1 + i);
	i = start - s1;
	y = 0;
	while (i <= (end - s1))
	{
		*(array + y) = *(s1 + i);
		i++;
		y++;
	}
	return (array);
}
