/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluba <dluba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:27:34 by dluba             #+#    #+#             */
/*   Updated: 2022/02/16 18:28:09 by dluba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	clear_memory(char **big_str)
{
	int	i;

	i = 0;
	while (big_str[i] != NULL)
		free(big_str[i++]);
	free(big_str);
}

int	get_width(char *file)
{
	int		fd;
	int		counter;
	char	**split_str;
	char	*str;

	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("openclose_error: Cannot open file\n");
		exit(0);
	}
	str = get_next_line(fd);
	split_str = ft_split(str, ' ');
	while (split_str[counter] != NULL)
		counter++;
	close(fd);
	free(str);
	clear_memory(split_str);
	return (counter);
}

int	get_height(char *file)
{
	int		fd;
	int		counter;
	char	*str;

	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("openclose_error: Cannot open file\n");
		exit(0);
	}
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_printf("line was detected: %d\n", counter + 1);
		counter++;
		free(str);
		str = get_next_line(fd);
	}
	write(1, "\n\n\n", 3);
	close(fd);
	return (counter);
}

void	small_array_dealer(char *str, int i, t_data *data)
{
	char	**big_str;
	int		j;

	j = 0;
	data->map[i] = (int *)malloc(sizeof(int) * data->matrix_w + 1);
	big_str = ft_split(str, ' ');
	if (!data->map[i] || !big_str)
		exit (0);
	while (big_str[j] != NULL && big_str[j] != 0 && big_str[j][0] != '\n' \
		&& big_str[j][0] != ' ')
	{
		data->map[i][j] = ft_atoi(big_str[j]);
		j++;
	}
	if (j < data->matrix_w)
	{
		ft_printf("\nmap_error\n");
		exit (0);
	}
	clear_memory(big_str);
	free(str);
}

void	get_map(char *file, t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("openclose_error: Cannot open file\n");
		exit(0);
	}
	data->map = (int **)malloc(sizeof(int *) * data->matrix_h + 1);
	if (!data->map)
		exit(0);
	while (i < data->matrix_h)
	{
		small_array_dealer(get_next_line(fd), i, data);
		ft_printf("line was parsed\t%d/%d\n", i + 1, data->matrix_h);
		i++;
	}
	data->map[i] = NULL;
}
