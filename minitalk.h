/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:17:52 by pandalaf          #+#    #+#             */
/*   Updated: 2022/10/28 13:54:22 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "./libft/libft.h"
# ifndef DELAY
#  define DELAY 50
# endif

//Function
void	end_signal(int pid);
//Function
void	char_signal(char ch, int pid);
//Function
void	string_signal(char *str, int pid);
#endif