/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:22 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:12 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	display_checker(int x, int y, t_data *data)
{
	if (x >= data->screen_w || y >= data->screen_h)
		return (-1);
	if (x < 0 || y < 0)
		return (-1);
	return (0);
}

void	set_drawline_vars(t_data *data, t_draw *vars)
{
	vars->r_start = get_r(vars->color_1);
	vars->g_start = get_g(vars->color_1);
	vars->b_start = get_b(vars->color_1);
	vars->d_r = get_r(vars->color_2) - get_r(vars->color_1);
	vars->d_g = get_g(vars->color_2) - get_g(vars->color_1);
	vars->d_b = get_b(vars->color_2) - get_b(vars->color_1);
	vars->x_start = data->x1;
	vars->y_start = data->y1;
	vars->cell_len = sqrt(pow((data->x2 - data->x1), 2) \
					+ pow((data->y2 - data->y1), 2));
	vars->delta_x = abs((data->x2 - data->x1));
	vars->delta_y = abs((data->y2 - data->y1));
	vars->sign_x = sign(data->x1, data->x2);
	vars->sign_y = sign(data->y1, data->y2);
	vars->error = vars->delta_x - vars->delta_y;
}

void	drawline(int i, int j, t_data *data, int w_flag)
{
	t_draw	vars;

	data->where_flag = w_flag;
	shift_isometry_zoom(data, i, j);
	set_color_percent(data, &vars, i, j);
	choose_dots_color(data, &vars);
	set_drawline_vars(data, &vars);
	if (display_checker(data->x2, data->y2, data) == 0)
		my_pix_put(data, data->x2, data->y2, vars.color_2);
	while (data->x1 != data->x2 || data->y1 != data->y2)
	{
		if (display_checker(data->x1, data->y1, data) == 0)
			my_pix_put(data, data->x1, data->y1, choose_color(data, &vars));
		vars.error2 = vars.error * 2;
		if (vars.error2 > -vars.delta_y)
		{
			vars.error -= vars.delta_y;
			data->x1 += vars.sign_x;
		}
		if (vars.error2 < vars.delta_x)
		{
			vars.error += vars.delta_x;
			data->y1 += vars.sign_y;
		}
	}
}

void	set_picture(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->matrix_h)
	{
		j = 0;
		while (j < data->matrix_w)
		{
			if (j < data->matrix_w - 1)
				drawline(i, j, data, 0);
			if (i < data->matrix_h - 1)
				drawline(i, j, data, 1);
			j++;
		}
		i++;
	}
}
