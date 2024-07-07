/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:25:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/07 21:27:09 by nbellila         ###   ########.fr       */
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
			map->pos[y][x]->z = map->tab[y][x];
			x++;
		}
		y++;
	}
}

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
		data->img->img, 0, 0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit_success(data);
	if (keycode == ' ')
	{
		reset_pos(data->map);
		data->tetha = 0;
		data->gamma = 0;
		data->alpha = 0;
		data->x = 0;
		data->spacing = get_default_zoom(data);
	}
	if (keycode == 'w')
		data->y += 50;
	if (keycode == 'a')
		data->x += 50;
	if (keycode == 's')
		data->y -= 50;
	if (keycode == 'd')
		data->x -= 50;
	if (keycode == 'z')
		data->alpha += 0.1;
	if (keycode == 'x')
		data->tetha += 0.1;
	if (keycode == 'v')
		data->gamma += 0.1;
	redraw_img(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->spacing += 2;
	if (button == 5 && data->spacing > 1)
		data->spacing -= 2;
	redraw_img(data);
	x++;
	y++;
	return (0);
}
