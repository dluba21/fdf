/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:27:36 by dluba             #+#    #+#             */
/*   Updated: 2021/12/29 19:27:36 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	power_printf(int factor, int n)
{
	unsigned int	a;

	a = (unsigned int)factor;
	if (n == 0)
		return (1);
	while (n-- > 1)
		a *= factor;
	return (a);
}

int	int_len_printf(int a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}
