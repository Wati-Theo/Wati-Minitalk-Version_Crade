/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:50:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/17 03:29:35 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

t_msg msg;

char	oui[2000];
int		non = 0;

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

void	binary_to_char(int bit)
{
	static int	i;

	printf("i: %d	bit: %d	%s\n", i, bit, oui);
	if (msg.current_char_byte < 8)
	{
		if (bit)
			msg.msg[i] += ft_iterative_power(2, 7 - msg.current_char_byte);
		// msg.msg[i] = (msg.msg[i]<<1) + bit;
		msg.current_char_byte++;
	}
	if (msg.current_char_byte == 8)
	{
		msg.current_char_byte = 0;
		printf("%c, %d\n", msg.msg[i], msg.msg[i]);
		i++;
	}	
	
}

void	siga(int bit)
{
	if (msg.current_trame_byte < 30) // taille msg
	{
		if (bit)
		{
			printf("1");
			msg.msg_len += ft_iterative_power(2, 30 - msg.current_trame_byte);
		}
		else
			printf("0");
	}
	else if (msg.current_trame_byte == 30)
	{
		printf(" msg_len: %d\n", msg.msg_len);
		msg.msg = malloc(sizeof(char) * (msg.msg_len + 1));
	}
	else
		binary_to_char(bit);
	msg.current_trame_byte++;
}

void	on_sigusr1(int sig)
{
	oui[non++] = '0';
	siga(0);
	// dprintf(1, "0");
	// msg.current_trame_byte++;
	// if (msg.current_trame_byte >= 31)
	// {
	// 	printf(" msg_len: %d\n", msg.msg_len);
	// 	printf("0");
	// 	binary_to_char();
	// 	msg.current_char_byte++;
	// }
}

void	on_sigusr2(int sig)
{
	oui[non++] = '1';
	siga(1);
	// dprintf(1, "1");
	// msg.current_trame_byte++;
	// msg.msg_len += ft_iterative_power(2, 31 - msg.current_trame_byte);
	// if (msg.current_trame_byte >= 31)
	// {
	// 	printf(" msg_len: %d\n", msg.msg_len);
	// 	printf("0");
	// 	binary_to_char();
	// 	msg.current_char_byte++;
	// }
}

int	main(int argc, char *argv[])
{
	msg.msg = NULL;
	msg.msg_len = 0;
	msg.current_trame_byte = 0;
	msg.current_char_byte = 0;
	signal(SIGUSR1, &on_sigusr1);
	signal(SIGUSR2, &on_sigusr2);
	printf("LE PID EST %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}