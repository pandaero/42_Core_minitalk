/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:31:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 17:46:21 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//Function displays message-received signal.
void	msgrcv(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message was received by the server.\n");
}

//Main program, takes PID and string arguments to send a signal to the PID. 
int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("Input Error.\n");
		return (0);
	}
	string_signal(argv[2], ft_atoi(argv[1]));
	act.sa_handler = &msgrcv;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &act, 0) == -1)
	{
		ft_printf("Sigaction error.\n");
		exit(0);
	}
	pause();
	return (0);
}
