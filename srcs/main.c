/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 06:21:23 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	dst = img->addr + offset;
	*(unsigned int*)dst = color;
}

static void	draw_map(t_data *data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < data->map->width)
	{
		y = 0;
		while (y < data->map->height)
		{
			my_mlx_pixel_put(data->img, x * 10, y * 10, GREEN);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*data;

	if (argc != 2)
		exit_args();
	check_file(argv[1]);
	map = get_map(argv[1]);
	data = init_data(map);
	if (!data || !init_mlx(data))
	{
		free_data(data);
		exit_error("An allocation failed");
	}
	show_map(map);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_loop(data->mlx);
	exit_success(data);
}
