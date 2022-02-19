/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:41 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:42 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	case_integer_printf(int a)
{
	int	counter;

	counter = int_len_printf(a);
	ft_putnbr(a);
	if (a < 0)
		counter++;
	return (counter);
}

int	case_unsigned_printf(unsigned int a)
{
	int		len;
	int		i;

	len = u_len_printf(a, 10);
	i = len;
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len--)
	{
		ft_putchar(a / power_printf(10, len) + '0');
		a %= power_printf(10, len);
	}
	return (i);
}

int	case_x_printf(unsigned int a, int flag)
{
	char	*str;
	int		len;
	int		i;

	len = u_len_printf(a, 16);
	i = len;
	if (flag)
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (a == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (len--)
	{
		ft_putchar(str[a / power_printf(16, len)]);
		a %= power_printf(16, len);
	}
	return (i);
}

unsigned long	lu_power_printf(int factor, int n)
{
	unsigned long	a;

	a = (unsigned long)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}

int	lu_len_printf(unsigned long a, int b)
{
	int	len;

	len = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= b;
		len++;
	}
	return (len);
}
