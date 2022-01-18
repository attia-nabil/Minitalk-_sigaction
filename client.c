/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:31:58 by nattia            #+#    #+#             */
/*   Updated: 2022/01/17 21:32:02 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		usleep(500);
		kill(pid, (c >> i & 1) + SIGUSR1);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	i = 0;
	if (ac != 3)
	{
		write(2, "not enough arguments", 20);
		return (0);
	}
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
}
