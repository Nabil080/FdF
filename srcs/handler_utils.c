/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:41:18 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 17:51:19 by nbellila         ###   ########.fr       */
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

void	*redraw_img(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img->img)
		return (NULL);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length,
			&data->img->endian);
	if (!data->img->addr)
		return (NULL);
	reset_pos(data->map);
	transform_points(data);
	draw_lines(*data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->img, 0, 0);
	show_inputs(*data);
	return (data);
}

void	reset_img(t_data *data)
{
	reset_pos(data->map);
	data->tetha = 0;
	data->gamma = 0;
	data->alpha = 0;
	data->x = 0;
	data->zoom = get_default_zoom(data);
}
