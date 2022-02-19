/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rot_and_iso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:48 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:06 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	isometry(t_data *data)
{
	float	temp_x;

	temp_x = data->x1;
	data->x1 = (int)((temp_x + data->y1) * sin(data->angle) - data->z1);
	data->y1 = (int)((temp_x - data->y1) * cos(data->angle));
	temp_x = data->x2;
	data->x2 = (int)((temp_x + data->y2) * sin(data->angle) - data->z2);
	data->y2 = (int)((temp_x - data->y2) * cos(data->angle));
}

void	rotate_x(t_data *data)
{
	float	temp_y;

	temp_y = data->y1;
	data->y1 = (int)(temp_y * cos(data->angle_x) + \
					data->z1 * sin(data->angle_x));
	data->z1 = (int)(-temp_y * sin(data->angle_x) + \
					data->z1 * cos(data->angle_x));
	temp_y = data->y2;
	data->y2 = (int)(temp_y * cos(data->angle_x) + \
					data->z2 * sin(data->angle_x));
	data->z2 = (int)(-temp_y * sin(data->angle_x) + \
					data->z2 * cos(data->angle_x));
}

void	rotate_y(t_data *data)
{
	float	temp_x;

	temp_x = data->x1;
	data->x1 = (int)(temp_x * cos(data->angle_y) + \
					data->z1 * sin(data->angle_y));
	data->z1 = (int)(-temp_x * sin(data->angle_y) + \
					data->z1 * cos(data->angle_y));
	temp_x = data->x2;
	data->x2 = (int)(temp_x * cos(data->angle_y) + \
					data->z2 * sin(data->angle_y));
	data->z2 = (int)(-temp_x * sin(data->angle_y) + \
					data->z2 * cos(data->angle_y));
}

void	rotate_z(t_data *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = data->x1;
	temp_y = data->y1;
	data->x1 = (int)(temp_x * cos(data->angle_z) - temp_y * sin(data->angle_z));
	data->y1 = (int)(temp_x * sin(data->angle_z) + temp_y * cos(data->angle_z));
	temp_x = data->x2;
	temp_y = data->y2;
	data->x2 = (int)(temp_x * cos(data->angle_z) - temp_y * sin(data->angle_z));
	data->y2 = (int)(temp_x * sin(data->angle_z) + temp_y * cos(data->angle_z));
}
