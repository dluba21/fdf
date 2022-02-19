/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:39 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:08 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	ft_cross_button(void)
{
	exit (0);
}

void	return_to_begin(t_data *data)
{
	data->axis_zoom = ft_min(data->screen_w, data->screen_h) / \
					(2 * ft_max(data->matrix_w, data->matrix_h));
	data->shift_x = data->screen_w / 2 - data->axis_zoom * data->matrix_w / 2;
	data->shift_y = data->screen_h / 2 - data->axis_zoom * data->matrix_h / 2;
	data->angle = 0.7;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->z_zoom = 3;
}

void	which_key_cases_1(int key, t_data *data)
{
	if (key == 123)
		data->shift_x -= 15;
	else if (key == 124)
		data->shift_x += 15;
	else if (key == 125)
		data->shift_y += 15;
	else if (key == 126)
		data->shift_y -= 15;
	else if (key == 29 && data->isometry_flag == 1)
			data->isometry_flag = 0;
	else if (key == 29 && data->isometry_flag == 0)
		data->isometry_flag = 1;
	else if (key == 30)
		data->z_zoom += 0.2;
	else if (key == 33)
		data->z_zoom -= 0.2;
	else if (key == 22)
		data->angle_x -= 0.05;
}

void	which_key_cases_2(int key, t_data *data)
{
	if (key == 23)
		data->angle_x += 0.05;
	else if (key == 20)
		data->angle_y -= 0.05;
	else if (key == 21)
		data->angle_y += 0.05;
	else if (key == 18)
		data->angle_z -= 0.05;
	else if (key == 19)
		data->angle_z += 0.05;
	else if (key == 28)
		data->angle -= 0.05;
	else if (key == 25)
		data->angle += 0.05;
	else if (key == 27)
		data->axis_zoom /= 1.2;
	else if (key == 24)
		data->axis_zoom *= 1.2;
	else if (key == 51)
		return_to_begin(data);
	else if (key == 53)
		exit(0);
}

int	which_key(int key, t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	data->addr = mlx_get_data_addr(data->img, \
								&data->bpr, &data->l_len, &data->e);
	which_key_cases_1(key, data);
	which_key_cases_2(key, data);
	set_picture(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
