/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:32:09 by nattia            #+#    #+#             */
/*   Updated: 2022/01/17 21:32:12 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(pid, (c >> i & 1) + SIGUSR1);
		usleep(500);
		i--;
	}
}

void	handler(int sig)
{
	(void)sig;
	write(1, "Server: successfully recieved\n", 29);
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "not enough arguments\n", 30);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	signal(SIGUSR1, handler);
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char(0, pid);
}
