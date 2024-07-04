/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:25:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/04 19:56:44 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->pos[y][x]->x = x;
			map->pos[y][x]->y = y;
			x++;
		}
		y++;
	}
}

// static void	reput_img(t_data *data)
// {
// 	mlx_clear_window(data->mlx, data->win);
// 	mlx_put_image_to_window(data->mlx, data->win,
// 		data->img->img, data->x, data->y);
// }

static void	redraw_img(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length,
			&data->img->endian);
	reset_pos(data->map);
	draw_points(data);
	draw_lines(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->img, data->x, data->y);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_success(data);
	if (keycode == 'w')
	{
		data->y += 20;
		redraw_img(data);
	}
	if (keycode == 'a')
	{
		data->x += 20;
		redraw_img(data);
	}
	if (keycode == 's')
	{
		data->y -= 20;
		redraw_img(data);
	}
	if (keycode == 'd')
	{
		data->x -= 20;
		redraw_img(data);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
	{
		data->zoom += 1;
		redraw_img(data);
	}
	if (button == 5 && data->zoom > 1)
	{
		data->zoom -= 1;
		redraw_img(data);
	}
	x++;
	y++;
	return (0);
}
