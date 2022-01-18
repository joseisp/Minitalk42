/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- < jinacio-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:07:06 by jinacio-          #+#    #+#             */
/*   Updated: 2022/01/18 18:05:28 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int		convert_to_binary(unsigned long nbr, char *base);
char	*ft_itoa(int n);

int	ft_atoi(char	*str)
{
	int	num;

	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

void	error_init(int aux)
{
	if (aux == 1)
	{
		write (1, "Error, check the arguments.\n", 28);
		exit (1);
	}
	if (aux == 2)
	{
		write (1, "Error, check the conversion PID.\n", 33);
		exit (1);
	}
}

void	send_sinal(int bin, int pid)
{
	char	*i;
	int		j;

	i = ft_itoa(bin);
	j = 0;
	while (i[j])
	{
		if (i[j] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(2500);
		}
		else if (i[j] == '1')
		{
			kill (pid, SIGUSR2);
			usleep(2500);
		}
		j++;
	}
	free (i);
}

void	ignite_signal(char **text, int pid)
{
	int				i;
	int				binar;
	int unsigned	conv;

	i = 0;
	while (text[0][i])
	{
		conv = text[0][i];
		binar = convert_to_binary((unsigned long)conv, "01");
		send_sinal(binar, pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	aux;

	aux = 0;
	if (argc != 3)
	{
		aux = aux + 1;
		error_init(aux);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		aux = aux + 2;
		error_init(aux);
	}
	ignite_signal(&argv[2], pid);
}
