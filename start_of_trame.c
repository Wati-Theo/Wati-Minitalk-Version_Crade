/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_trame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wati-Theo <wati-theo@protonmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:52:32 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/17 02:45:57 by Wati-Theo        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

void	fill_byte(t_trame *trame, int choice)
{
	int	i;
	int size;

	size = 31;
	if (choice == 1)
		size = 8;
	i = ft_strlen(trame->byte_mssg);
	while (trame->byte_mssg[i] || i < size)
	{
		trame->byte_mssg[i] = '0';
		i++;
	}
	trame->byte_mssg[i] = 0;
}

void	decimal_to_binary(t_trame *trame, int n, int choice)
{
	int	bin;
	int	rem;
	int	place;
	int	i;
	
	bin = 0;
	rem = 0;
	place = 1;
	i = 0;
	if (choice	== 1)
		trame->byte_mssg = malloc(9 * sizeof(char));
	else
		trame->byte_mssg = malloc(32 * sizeof(char));
	while (n)
	{
		rem = n % 2;
		n = n / 2;
		bin = bin + (place * rem);
		place = place * 10;
		if (rem == 0)
			trame->byte_mssg[i] = '0';
		else
			trame->byte_mssg[i] = '1';
		i++;
	}
	trame->byte_mssg[i] = 0;
	fill_byte(trame, choice);
	reverse_str(trame, choice);
	printf("char_bin: $%s$\n", trame->byte_mssg);
	printf("bin: %d\n", bin);
	send_msg(trame);
}

void	start_of_trame(t_trame *trame)
{
	int	i;

	i = 0;
	decimal_to_binary(trame, trame->msg_len, 2);
	while(i < trame->msg_len)
	{
		decimal_to_binary(trame, trame->msg[i], 1);
		i++;
	}
	// les incantations d'antoine
	// while (i < 32)//trame->msg_len)
	// {
	// 	printf("%d ", (trame->msg_len>>(31 - i)) & 1);
	// 	// trame->current_bit = 0;
	// 	// decimal_to_binary(trame, trame->msg[i], 1);
	// 	i++;
	// }
}
