/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:42 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:07 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
	{
		ft_printf("arg_error: please, insert map!\n");
		exit(0);
	}
	if (argc > 2)
	{
		ft_printf("arg_error: too many maps!\n");
		exit(0);
	}
	set_default(&data, argv[1]);
	get_map(data.file, &data);
	get_color_extent(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.screen_w, \
								data.screen_h, "FDF");
	data.img = mlx_new_image(data.mlx, data.screen_w, data.screen_h);
	data.addr = mlx_get_data_addr(data.img, &data.bpr, &data.l_len, &data.e);
	set_picture(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 17, 0, ft_cross_button, &data);
	mlx_hook(data.mlx_win, 2, 0, which_key, &data);
	mlx_loop(data.mlx);
}
