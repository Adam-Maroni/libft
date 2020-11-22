/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <amaroni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:24:04 by amaroni           #+#    #+#             */
/*   Updated: 2020/11/22 12:25:08 by amaroni          ###   ########.fr       */
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

static int	ft_isdigit(int c)
{
	if (((c >= '0') && (c <= '9')))
		return (2048);
	return (0);
}

static void	*ft_calloc(int nmemb, int size)
{
	void	*rt_pointer;
	int		i;

	i = 0;
	rt_pointer = (void*)malloc(nmemb * size);
	while (i < nmemb)
	{
		*((int*)rt_pointer + i) = 0;
		i++;
	}
	return (rt_pointer);
}

int	ft_atoi(char *nptr)
{
	int i;
	int rt;
	int x10;
	char *array;

	i = 0;
	rt = 0;
	x10 = 1;
	while (ft_isdigit(*(nptr + i)) > 0)
		i++;
	if (i == 0)
		return (0);
	array = (char*)ft_calloc((i + 1), sizeof(char));
	while (i > 0)
	{
		*(array + (i - 1)) = *(nptr + (i - 1));
		i--;
	}
	i = ft_strlen(array);
	while (i > 0)
	{
		rt += ((*(array + (i - 1)) - '0') * (x10));
		x10 *= 10;
		i--;
	}
	free(array);
	return (rt);
}
