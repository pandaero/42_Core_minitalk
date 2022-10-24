/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:47 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 01:38:52 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

// Variable serves as a received signal (bit) counter.
static unsigned int	ct;

//Function acts when a signal is received.
void	sigrcv(int sig)
{
	unsigned int	arr[8];
	unsigned int	num;
	int				i;

	if (sig == SIGUSR1)
		arr[ct % 8] = 0;
	if (sig == SIGUSR2)
		arr[ct % 8] = 1;
	if (ct > 1 && (ct + 1) % 8 == 0)
	{
		num = 0;
		i = 0;
		while (i < 8)
		{
			num = num * 2 + arr[i];
			i++;
		}
		if (num == 255)
		{
			write(1, "\n", 1);
			return ;
		}
		write(1, &num, 1);
	}
	ct++;
	return ;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d. Receiving...\n", pid);
	signal(SIGUSR1, sigrcv);
	signal(SIGUSR2, sigrcv);
	while (1);
	return (0);
	
	// Display own PID
	// Be ready to receive signals
	// Write signals when received
	// Take string from input
	// Send string to server (PID)
}
