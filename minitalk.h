/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:33:02 by nattia            #+#    #+#             */
/*   Updated: 2022/01/17 21:33:05 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

struct	s_recieved
{
	int		n;
	char	c;
	int		pid;
}		t_recieved;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

#endif
