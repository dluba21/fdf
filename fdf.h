/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:55 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:07 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <mlx.h>
# define RED_CHROMA 0
# define GREEN_CHROMA 255
# define BLUE_CHROMA 255

typedef struct s_data {
	char	*file;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpr;
	int		l_len;
	int		e;
	int		screen_w;
	int		screen_h;
	int		**map;
	float	**col_ext;
	int		begin_x;
	int		begin_y;
	int		shift_x;
	int		shift_y;
	int		matrix_w;
	int		matrix_h;
	float	angle;
	int		isometry_flag;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	z_zoom;
	float	axis_zoom;
	int		x1;
	int		y1;
	int		z1;
	int		x2;
	int		y2;
	int		z2;
	int		min_z;
	int		max_z;
	int		where_flag;
}				t_data;

typedef struct s_draw
{
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		error;
	int		error2;
	int		color;
	int		max_z;
	int		min_z;
	float	delta_color;
	int		current_color;
	int		x_start;
	int		y_start;
	float	color_1;
	float	color_2;
	int		cell_len;
	int		r_start;
	int		g_start;
	int		b_start;
	int		d_r;
	int		d_g ;
	int		d_b ;
	float	percent1;
	float	percent2;
}			t_draw;

int		get_width(char *file);

int		get_height(char *file);

void	small_array_dealer(char *str, int i, t_data *data);

void	get_map(char *file, t_data *data);

void	find_min_max_z(t_data *data);

void	get_color_extent(t_data *data);

int		ft_min(int a, int b);

int		ft_max(int a, int b);

void	my_pix_put(t_data *data, int x, int y, int color);

int		sign(int a, int b);

void	isometry(t_data *data);

void	shift_x_and_y(t_data *data);

void	rotate_x(t_data *data);

void	rotate_y(t_data *data);

void	rotate_z(t_data *data);

void	shift_isometry_zoom(t_data *data, int i, int j);

int		create_trgb(int t, int r, int g, int b);

int		get_t(int trgb);

int		get_r(int trgb);

int		get_g(int trgb);

int		get_b(int trgb);

int		choose_color(t_data *data, t_draw *vars);

void	set_color_percent(t_data *data, t_draw *vars, int i, int j);

int		choose_dots_color(t_data *data, t_draw *vars);

int		display_checker(int x, int y, t_data *data);

void	set_drawline_vars(t_data *data, t_draw *vars);

void	drawline(int i, int j, t_data *data, int w_flag);

void	set_picture(t_data *data);

void	set_default(t_data *data, char *str);

void	return_to_begin(t_data *data);

void	which_key_cases_1(int key, t_data *data);

void	which_key_cases_2(int key, t_data *data);

int		which_key(int key, t_data *data);

int		ft_cross_button(void);

#endif
