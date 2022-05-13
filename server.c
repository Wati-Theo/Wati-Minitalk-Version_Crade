/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:50:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/10 14:31:03 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

t_msg msg;

void	decode_byte(void)
{
	return	;
}

int	ft_iterative_power(int nb, int power)
{
	int	resultat;

	resultat = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power)
	{
		resultat = resultat * nb;
		power--;
	}
	return (resultat);
}

void	binary_to_char(void)
{
	
}

void	siga(int bit)
{
	msg.current_read_trame_byte++;
	if (msg.current_read_trame_byte < 31)
		//add to len
	else if (msg.current_read_char_byte == 32)
		//malloc msg.msg
	else
		//lire message, binary to char
}

void	on_sigusr1(int sig)
{
	siga(0);
	// printf("0");
	// msg.current_read_trame_byte++;
	// if (msg.current_read_trame_byte >= 31)
	// {
	// 	printf(" msg_len: %d\n", msg.msg_len);
	// 	printf("0");
	// 	binary_to_char();
	// 	msg.current_read_char_byte++;
	// }
}

void	on_sigusr2(int sig)
{
	siga(1);
	// printf("1");
	// msg.current_read_trame_byte++;
	// msg.msg_len += ft_iterative_power(2, 31 - msg.current_read_trame_byte);
	// if (msg.current_read_trame_byte >= 31)
	// {
	// 	printf(" msg_len: %d\n", msg.msg_len);
	// 	printf("0");
	// 	binary_to_char();
	// 	msg.current_read_char_byte++;
	// }
}

int	main(int argc, char *argv[])
{
	msg.msg = NULL;
	msg.msg_len = 0;
	msg.current_read_trame_byte = 0;
	signal(SIGUSR1, &on_sigusr1);
	signal(SIGUSR2, &on_sigusr2);
	printf("LE PID EST %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}