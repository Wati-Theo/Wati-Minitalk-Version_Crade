/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:50:13 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/17 03:16:15 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	send_msg(t_trame *trame)
{
	int	i;

	i = 0;
	while (trame->byte_mssg[i])
	{
		usleep(400);
		if (trame->byte_mssg[i] == '0')
			kill(trame->pid, SIGUSR1);
		if (trame->byte_mssg[i] == '1')
			kill(trame->pid, SIGUSR2);
		i++;
	}
	free (trame->byte_mssg);
}

void	wati_trame(t_trame *trame)
{
	start_of_trame(trame);
}

/*
**  La Trame : Les 31 premiers bits representent la taille du mssg 
**	1111111111111111111111111111111
*/

int	main(int argc, char *argv[])
{
	t_trame	trame;

	if (argc != 3)
		return (1);
	trame.msg_len = ft_strlen(argv[2]);
	trame.pid = atoi(argv[1]);
	trame.msg = ft_strdup(argv[2]);
	wati_trame(&trame);
}