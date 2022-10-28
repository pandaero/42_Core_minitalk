/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 17:39:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

//Variable serves as a received signal (bit) counter.
static unsigned int	g_ct;

//Function clears the array.
void	reset_sig(unsigned int *arr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		arr[i] = 0;
		i++;
	}
}

//Function acts when a signal is received. Emits receive upon EOT.
void	sigrcv_bonus(int sig, siginfo_t *info, void *context)
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
			num = num * 2 + arr[i++];
		if (num == 255 && context)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			write(1, &num, 1);
	}
	g_ct++;
}

//Main program, broadcasts PID to receive signals. Sets PID sender catching.
int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_sigaction = &sigrcv_bonus;
	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	pid = getpid();
	printf("PID: %d. Receiving...\n", pid);
	if (sigaction(SIGUSR1, &act, 0) == -1 || sigaction(SIGUSR2, &act, 0) == -1)
	{
		ft_printf("Sigaction error.\n");
		exit(0);
	}
	while (1)
		pause();
	return (0);
}
