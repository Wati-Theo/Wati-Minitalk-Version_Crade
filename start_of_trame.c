/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_trame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:52:32 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/09 19:52:33 by tschlege         ###   ########lyon.fr   */
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
		// printf ("rem: %d place: %d, n: %d\n", rem, place, n);
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
	// reverse_tab(trame, i);
	fill_byte(trame, choice);
	reverse_str(trame, choice);
	printf("char_bin: %s\n", trame->byte_mssg);
	printf("bin: %d\n", bin);
	send_msg(trame);
}

void	start_of_trame(t_trame *trame)
{
	int	i;
	trame->current_bit = 0;
	
	// i = -1;
	// while (++i < 32)
	// {
	// 	printf("%c", (trame->msg_len>>(31 - i)) & 1 + '0');
	// }
	decimal_to_binary(trame, trame->msg_len, 2);
}
