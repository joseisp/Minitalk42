/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:24:50 by jinacio-          #+#    #+#             */
/*   Updated: 2022/01/14 22:14:40 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

static void	convert(int c, char *str, long int i)
{
	unsigned int	nbr;

	nbr = c;
	if (c < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr >= 10)
		convert((nbr / 10), str, (i - 1));
	str[i] = (nbr % 10) + '0';
}

char	*put_zero(char *str)
{
	int		i;
	char	*aux;
	char	*send;

	i = ft_strlen(str);
	if (i == 7)
	{
		aux = "0";
		send = ft_strjoin(aux, str);
	}
	else if (i == 6)
	{
		aux = "00";
		send = ft_strjoin(aux, str);
	}
	return (send);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	j;
	long int	count;
	char		*send;

	j = n;
	count = 0;
	if (j <= 0)
		count++;
	while (j)
	{
		j = (j / 10);
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = 0;
	convert (n, str, (count - 1));
	send = put_zero(str);
	free (str);
	return (send);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t sizedest)
{
	size_t	nbytes;
	size_t	i;

	i = 0;
	nbytes = ft_strlen(src);
	if (!src || !dest)
		return (0);
	if (sizedest != 0)
	{
		while (src[i] != '\0' && i < (sizedest - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (nbytes);
}
