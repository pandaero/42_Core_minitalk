/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 16:06:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <unistd.h>
#include <signal.h>
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
		//reset_sig(arr);
	}
	g_ct++;
}

//Main program, broadcasts PID to receive signals.
int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d. Receiving...\n", pid);
	signal(SIGUSR1, sigrcv);
	signal(SIGUSR2, sigrcv);
	while (1)
		usleep(10);
	return (0);
}
