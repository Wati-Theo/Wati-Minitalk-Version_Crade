/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wati_Minitalk.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:51:16 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/09 19:51:17 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WATI_MINITALK_H
# define WATI_MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_msg {
	int		msg_len;
	int 	current_read_byte;
	char	*msg;
}	t_msg;

extern	t_msg msg;

typedef struct s_trame {
	int		pid;
	int		msg_len;
	int		current_bit;
	char	*str_len;
	char	*msg;
	char	*byte_mssg;
}	t_trame;

int		ft_strlen(const	char *s);
char	*ft_strdup(const char *s1);
void	add_last_bit(t_trame *trame, int choice);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	reverse_str(t_trame *trame, int choice);
void	fill_byte(t_trame *trame, int choice);
void	wati_trame(t_trame *trame);
void	send_msg(t_trame *trame);
void	start_of_trame(t_trame *trame);
void	decimal_to_binary(t_trame *trame, int n, int choice);

#endif