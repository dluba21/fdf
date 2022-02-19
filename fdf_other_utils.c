/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_other_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:45 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:05 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void	my_pix_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpr / 8));
	*(unsigned int *)dst = color;
}

int	sign(int a, int b)
{
	if (a <= b)
		return (1);
	return (-1);
}

void	set_default(t_data *data, char *str)
{
	data->file = str;
	data->matrix_h = get_height(data->file);
	data->matrix_w = get_width(data->file);
	data->screen_w = 1000;
	data->screen_h = 1000;
	data->axis_zoom = ft_min(data->screen_w, data->screen_h) / \
					(2 * ft_max(data->matrix_w, data->matrix_h));
	data->shift_x = 0;
	data->shift_y = 0;
	data->angle = 0.7;
	data->isometry_flag = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->z_zoom = 1;
}
