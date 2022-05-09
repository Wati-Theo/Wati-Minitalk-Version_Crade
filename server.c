/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:50:46 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/09 19:50:47 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

t_msg msg;

void	decode_byte(void)
{
	return	;
}

void	on_sigusr1(int sig)
{
	printf("0");
	msg.current_read_byte++;
	msg.msg_len << 1;
	if (msg.current_read_byte == 31)
	{
		printf("msg_len: %d\n", msg.msg_len);
	}
}

void	on_sigusr2(int sig)
{
	printf("1");
	msg.current_read_byte++;
	msg.msg_len << 1;
	if (msg.current_read_byte == 31)
	{
		printf("msg_len: %d\n", msg.msg_len);
	}
	msg.msg_len++;
			
}

int	main(int argc, char *argv[])
{
	msg.msg = NULL;
	msg.msg_len = 0;
	msg.current_read_byte = 0;
	signal(SIGUSR1, &on_sigusr1);
	signal(SIGUSR2, &on_sigusr2);
	printf("LE PID EST %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}