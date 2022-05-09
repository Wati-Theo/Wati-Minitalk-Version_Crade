/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschlege <tschlege@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:51:36 by tschlege          #+#    #+#             */
/*   Updated: 2022/05/09 19:51:43 by tschlege         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Wati_Minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (i >= '0' && i <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

int	ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*copy;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s1_len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}


void	ft_putchar(char c)
{
	write(2, &c, 1);
}

void	reverse_str(t_trame *trame, int choice)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = 0;
	size = 30;
	if (choice == 1)
		size = 8;
	j = size;
	tmp = ft_strdup(trame->byte_mssg);
	while (size + 1)
	{
		trame->byte_mssg[i] = tmp[size];
		i++;
		size--;
	}
}
