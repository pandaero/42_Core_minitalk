/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:17:52 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 14:28:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# ifndef DELAY
#  define DELAY 50
# endif

//Function emits a message-end signal.
void	end_signal(int pid);
//Function creates a signal for a character.
void	char_signal(char ch, int pid);
//Function creates a signal for an entire string.
void	string_signal(char *str, int pid);
#endif