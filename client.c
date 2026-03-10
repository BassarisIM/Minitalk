/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:50:06 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/06 18:30:32 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	g_wait;

void	client_handler(int signum)
{
	g_wait = 0;
	(void)signum;
	return ;
}

void	send_bit(int pid, int countbits, char c)
{
	if ((c >> countbits) & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	int		countbits;
	int		pid;

	g_wait = -1;
	if (argc != 3 || !ft_atoi((const char *)argv[1]) \
		|| ft_atoi((const char *)argv[1]) < 0)
		return (1);
	signal(SIGUSR2, client_handler);
	pid = ft_atoi((const char *)argv[1]);
	i = 0;
	while (argv[2][i])
	{
		countbits = 8;
		c = (unsigned char)argv[2][i];
		while (--countbits >= 0)
		{
			send_bit(pid, countbits, c);
			while (g_wait == -1)
				;
			g_wait = -1;
		}
		i++;
	}
}
