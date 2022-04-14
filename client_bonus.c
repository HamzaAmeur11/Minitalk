/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:02:31 by hameur            #+#    #+#             */
/*   Updated: 2022/04/14 12:57:41 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"

//SIGUSR1 = 0
//SIGUSR2 = 1

void	mesg(int x)
{
	x = 0;
	write(1, "Message envoyer\n", 17);
	exit(0);
}

void	read_to_binary(char c, int pid)
{
	int	i;
	int	error;

	if (c == 0)
		signal(SIGUSR2, &mesg);
	i = 8;
	while (i-- > 0)
	{
		if ((c >> i) & 1)
			error = kill(pid, SIGUSR2);
		else
			error = kill(pid, SIGUSR1);
		usleep(800);
		if (error == -1)
			return (write(1, "Error sending signal\n", 22), exit(0));
	}
	return ;
}

void	usage(void)
{
	write(1, "./client pid “msg“\n", 18);
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*msg;

	i = -1;
	if (ac != 3)
		usage();
	msg = av[2];
	pid = ft_atoi(av[1]);
	while (msg[++i])
		read_to_binary(msg[i], pid);
	read_to_binary(msg[i], pid);
	while (1)
		pause();
	return (0);
}
