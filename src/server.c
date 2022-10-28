/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 13:21:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

//Variable serves as a received signal (bit) counter.
static unsigned int	g_ct;

//Function acts when a signal is received.
void	sigrcv(int sig)
{
	unsigned int	arr[8];
	unsigned int	num;
	int				i;

	if (sig == SIGUSR1)
		arr[g_ct % 8] = 0;
	if (sig == SIGUSR2)
		arr[g_ct % 8] = 1;
	if (g_ct > 1 && (g_ct + 1) % 8 == 0)
	{
		num = 0;
		i = 0;
		while (i < 8)
		{
			num = num * 2 + arr[i];
			i++;
		}
		if (num == 255)
			write(1, "\n", 1);
		else
			write(1, &num, 1);
	}
	g_ct++;
}

//Main program, broadcasts PID to receive signals.
int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_handler = &sigrcv;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaddset(&act.sa_mask, SIGINT);
	pid = getpid();
	printf("PID: %d. Receiving...\n", pid);
	if (sigaction(SIGUSR1, &act, 0) == -1 || sigaction(SIGUSR2, &act, 0) == -1)
	{
		ft_printf("Sigaction error.\n");
		exit(0);
	}
	while (1)
		usleep(SERVER_DELAY);
	return (0);
}
