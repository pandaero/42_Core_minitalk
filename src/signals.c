/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:27:22 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 14:28:11 by pandalaf         ###   ########.fr       */
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
