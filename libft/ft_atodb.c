/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:16:23 by dluba             #+#    #+#             */
/*   Updated: 2021/10/17 14:38:39 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	db_power(float factor, int n)
{
	float	a;

	a = (float)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}

static int	db_len(float number)
{
	int	i;

	i = 0;
	while (number >= 1)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static float	hex_to_decimal(char *str)
{
	int		i;
	float	mod;
	int		len;

	i = 0;
	mod = 0;
	len = ft_strlen(str) - 1;
	while (len > -1)
	{
		if (*str >= '0' && *str <= '9')
			mod += (*str - '0') * db_power(16, len--);
		else if (*str >= 'A' && *str <= 'F')
			mod += (*str - 'A' + 10) * db_power(16, len--);
		else if (*str >= 'a' && *str <= 'f')
			mod += (*str - 'a' + 10) * db_power(16, len--);
		str++;
	}
	return (mod * db_power(0.1, db_len(mod)));
}

static int	sign_checker(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

float	ft_atodb(char *str)
{
	int		i;
	int		j;
	int		sign;
	float	mod;

	i = 0;
	j = 0;
	mod = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (j > 0)
			return (0);
		sign = sign_checker(str[i++]);
		j++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		mod = mod * 10 + str[i++] - '0';
	if (str[i] == ',')
		mod += hex_to_decimal(str + 2);
	return (mod * sign);
}
