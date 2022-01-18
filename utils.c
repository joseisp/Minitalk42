/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:48:37 by jinacio-          #+#    #+#             */
/*   Updated: 2022/01/15 22:54:13 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t sizedest);
int		ft_atoi(char	*str);
int		ft_strlen(const char *c);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	p = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (p);
}

int	check_base( char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		size;

	size = ft_strlen(s1) + 1;
	cpy = (char *)malloc(size);
	if (cpy)
		ft_strlcpy (cpy, s1, size);
	return (cpy);
}

int	eternal_return(char *base, int nbr_final[], int i)
{
	char	*aux;
	char	*aux2;
	int		j;

	aux2 = (char *)malloc(sizeof(char *) * (i + 1));
	aux2[i + 1] = '\0';
	j = 0;
	while (--i >= 0)
	{
		if (base[nbr_final[i]] == '1')
			aux = "1";
		else
			aux = "0";
		aux2[j] = *aux;
		j++;
	}
	i = ft_atoi(aux2);
	free (aux2);
	return (i);
}

int	convert_to_binary(unsigned long nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	nbr = (unsigned int)nbr;
	if (check_base(base))
	{
		size_base = ft_strlen(&base[size_base]);
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
	}
	return (eternal_return(base, nbr_final, i));
}
