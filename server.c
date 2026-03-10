/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohollar <sohollar@student.42paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:48:29 by sohollar          #+#    #+#             */
/*   Updated: 2026/03/06 17:25:16 by sohollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *info, void *oldact)
{
	static int				nbits;
	static unsigned char	c;

	(void)oldact;
	c = c | (signum == SIGUSR1);
	if (nbits < 7)
	{
		c = c << 1;
		nbits++;
	}
	else
	{
		write(1, &c, 1);
		c = 0;
		nbits = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	ft_bzero(&action, sizeof(action));
	pid = getpid();
	ft_printf_fd(1, "PID serveur : %d\n", pid);
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
