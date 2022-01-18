/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:56:02 by jinacio-          #+#    #+#             */
/*   Updated: 2022/01/14 03:59:28 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd)
{
	write (1, &c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

void	receive_signal(int signal)
{
	static char	c = 255;
	static int	j = 0;

	if (signal == SIGUSR1)
	{
		c = c ^ (128 >> j);
	}
	++j;
	if (j == 8)
	{
		write(1, &c, 1);
		j = 0;
		c = 255;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_sig;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s_sig.sa_handler = receive_signal;
	sigemptyset(&s_sig.sa_mask);
	s_sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
	{
		pause();
	}
}
