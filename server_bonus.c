/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:56:36 by hameur            #+#    #+#             */
/*   Updated: 2022/04/14 14:23:00 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	write_h(char c, int pid)
{
	if (c)
		write(1, &c, 1);
	if (c == 0)
	{
		write(1, "\n", 1);
		kill(pid, SIGUSR2);
	}
}

void hand(int x)
{
	x = 0;
	write (1, "\nHHHH\n", 5);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static int	old_pid;
	static char	c;

	(void)ucontext;
	sig -= SIGUSR1;
	if (old_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		write(1, "\n", 1);
	}
	c = ((c << 1) | sig);
	i++;
	if (i == 8)
	{
		write_h(c, info->si_pid);
		c = 0;
		i = 0;
	}
	old_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID Server == ", 15);
	ft_putnbr_fd(getpid(), 1);
	while (1)
		pause();
	return (0);
}
