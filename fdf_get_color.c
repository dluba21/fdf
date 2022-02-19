/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:27 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:11 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	find_min_max_z(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->min_z = data->map[0][0];
	data->max_z = data->map[0][0];
	while (i < data->matrix_h)
	{
		j = 0;
		while (j < data->matrix_w)
		{
			if (data->map[i][j] >= data->max_z)
				data->max_z = data->map[i][j];
			if (data->map[i][j] <= data->min_z)
				data->min_z = data->map[i][j];
			j++;
		}
		i++;
	}
	data->min_z *= data->z_zoom;
	data->max_z *= data->z_zoom;
}

void	get_color_extent(t_data *data)
{
	int		i;
	int		j;
	float	d_z;

	i = 0;
	find_min_max_z(data);
	d_z = data->max_z - data->min_z;
	data->col_ext = (float **)malloc(sizeof(float *) * data->matrix_h);
	if (!data->col_ext)
		exit (0);
	while (i < data->matrix_h)
	{
		j = 0;
		data->col_ext[i] = (float *)malloc(sizeof(float) * data->matrix_w);
		if (!data->col_ext[i])
			exit (0);
		while (j < data->matrix_w)
		{
			data->col_ext[i][j] = (float)(data->map[i][j] - data->min_z) / d_z;
			j++;
		}
		i++;
	}
}

int	choose_color(t_data *data, t_draw *vars)
{
	int		red;
	int		green;
	int		blue;
	float	percent;

	percent = sqrt(pow((data->x1 - vars->x_start), 2) \
			+ pow((data->y1 - vars->y_start), 2)) / vars->cell_len;
	red = (int)(vars->r_start + percent * vars->d_r);
	green = (int)(vars->g_start + percent * vars->d_g);
	blue = (int)(vars->b_start + percent * vars->d_b);
	return (create_trgb(0, red, green, blue));
}

void	set_color_percent(t_data *data, t_draw *vars, int i, int j)
{
	vars->percent1 = data->col_ext[i][j];
	if (data->where_flag == 0)
		vars->percent2 = data->col_ext[i][j + 1];
	else if (data->where_flag == 1)
		vars->percent2 = data->col_ext[i + 1][j];
}

int	choose_dots_color(t_data *data, t_draw *vars)
{
	int	r;
	int	g;
	int	b;
	int	d_z;

	d_z = data->max_z - data->min_z;
	if (d_z == 0)
	{
		vars->color_1 = create_trgb(0, 0, 0, 255);
		vars->color_2 = create_trgb(0, 0, 0, 255);
		return (0);
	}
	r = RED_CHROMA;
	g = GREEN_CHROMA * vars->percent1;
	b = BLUE_CHROMA * (1 - vars->percent1);
	vars->color_1 = create_trgb(0, r, g, b);
	r = RED_CHROMA;
	g = GREEN_CHROMA * vars->percent2;
	b = BLUE_CHROMA * (1 - vars->percent2);
	vars->color_2 = create_trgb(0, r, g, b);
	return (0);
}
