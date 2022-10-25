/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:31:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/25 16:14:23 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>
#include <unistd.h>

//Function emits a message-end signal.
void	end_signal(int pid)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		kill(pid, SIGUSR2);
		usleep(DELAY);
		i++;
	}
}

//Function creates a signal for a character.
void	char_signal(char ch, int pid)
{
	unsigned int	num;
	unsigned int	store[8];
	int				i;

	num = (unsigned int) ch;
	i = 0;
	while (i < 8)
	{
		store[i] = num % 2;
		num /= 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (store[i] == 1)
			kill(pid, SIGUSR2);
		else if (store[i] == 0)
			kill(pid, SIGUSR1);
		usleep(DELAY);
		i--;
	}
}

//Function creates a signal for an entire string.
void	string_signal(char *str, int pid)
{
	while (*str != 0)
	{
		char_signal(*str, pid);
		str++;
	}
	end_signal(pid);
}

//Main program, takes PID and string arguments to send a signal to the PID. 
int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Input Error.\n");
		return (0);
	}
	string_signal(argv[2], ft_atoi(argv[1]));
	return (0);
}
