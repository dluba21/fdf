/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:50 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:34:37 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	shift_x_and_y(t_data *data)
{
	data->x1 += data->shift_x;
	data->y1 += data->shift_y;
	data->x2 += data->shift_x;
	data->y2 += data->shift_y;
}

void	shift_isometry_zoom(t_data *data, int i, int j)
{
	data->x1 = (int)(j * data->axis_zoom);
	data->y1 = (int)(i * data->axis_zoom);
	data->z1 = (int)(data->map[i][j] * data->z_zoom);
	if (data->where_flag == 0)
	{
		data->x2 = (int)((j + 1) * data->axis_zoom);
		data->y2 = (int)(data->y1);
		data->z2 = (int)(data->map[i][j + 1] * data->z_zoom);
	}
	else if (data->where_flag == 1)
	{
		data->x2 = (int)(data->x1);
		data->y2 = (int)((i + 1) * data->axis_zoom);
		data->z2 = (int)(data->map[i + 1][j] * data->z_zoom);
	}
	rotate_x(data);
	rotate_y(data);
	rotate_z(data);
	if (data->isometry_flag == 1)
		isometry(data);
	shift_x_and_y(data);
}
