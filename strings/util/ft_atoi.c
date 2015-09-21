/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 16:24:28 by jbyttner          #+#    #+#             */
/*   Updated: 2015/09/21 16:09:46 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strutil.h"

int		ft_atoi(char *str)
{
	int		sign;
	int		res;

	if (!str)
		return (0);
	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str == '0')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += (*str++ - '0') * sign;
	}
	return (res);
}

char	*ft_itoa(int value)
{
	int		magnitude;
	int		digit;
	char	*nbr;
	int		sign;

	if (!value)
		return ("0");
	digit = value;
	magnitude = 0;
	sign = ((value < 0) ? 1 : 0);
	while (digit != 0)
	{
		magnitude++;
		digit /= 10;
	}
	nbr = (char*)malloc(sizeof(char) * (magnitude + 1 + sign));
	nbr[0] = '-';
	nbr[magnitude + sign] = '\0';
	while (magnitude >= 0 + sign)
	{
		digit = value % 10;
		nbr[--magnitude + sign] = '0' + (digit < 0 ? -digit : digit);
		value = (value - digit) / 10;
	}
	return (nbr);
}
