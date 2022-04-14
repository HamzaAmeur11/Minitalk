/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:56:16 by hameur            #+#    #+#             */
/*   Updated: 2022/04/14 14:29:10 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<signal.h>
#include <stdlib.h>
#include "libft/libft.h"

void	write_h(char c)
{
	if (c != 0)
		write(1, &c, 1);
	else
		write(1, "\n", 1);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static int	old_pid;
	static char	c;

	sig -= 30;
	(void)ucontext;
	if (old_pid != info->si_pid)
	{
		write(1, "\n", 1);
		c = 0;
		i = 0;
	}
	c = ((c << 1) | sig);
	i++;
	if (i == 8)
	{
		write_h(c);
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
