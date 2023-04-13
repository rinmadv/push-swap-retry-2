/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madavid <madavid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:16:47 by madavid           #+#    #+#             */
/*   Updated: 2023/04/13 23:59:07 by madavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if ((str[i] == '-') || (str[i] == '+'))
		{
			if (str[i] == '-')
				sign = sign * -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9' )
		{
			nb = nb * 10 + str[i] - '0';
			i++;
		}
		return (nb * sign);
	}
	return (0);
}

int	countdigit(const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] == '0' && str[i + 1] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' )
	{
		j++;
		i++;
	}
	if (str[i] != 0)
		return (-1);
	return (j);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
