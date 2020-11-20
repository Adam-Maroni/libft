size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t i;
	size_t y;

	i = 0;
	y = 0;
	while ( *(dst + y) != '\0')
		y++;
	while (i < size - 1)
	{
		*(dst + y) = *(src + i);
		y++;
		i++;
	}
	*(dst + y ) = '\0';
	while (*(src + i) != '\0')
	{
		y++;
		i++;
	}
	return (y);
}
