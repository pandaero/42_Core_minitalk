/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:31:39 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 14:27:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <signal.h>
#include <unistd.h>

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
