/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 02:49:10 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_color(t_data data, int z)
{
	int	threshold;

	threshold = (data.map->highest - data.map->lowest) / 10;
	if (!threshold)
		threshold++;
	if (z >= data.map->lowest + threshold * 9)
		return (GRADIENT_9);
	if (z >=  data.map->lowest + threshold * 8)
		return (GRADIENT_8);
	if (z >=  data.map->lowest + threshold * 7)
		return (GRADIENT_7);
	if (z >=  data.map->lowest + threshold * 6)
		return (GRADIENT_6);
	if (z >=  data.map->lowest + threshold * 5)
		return (GRADIENT_5);
	if (z >=  data.map->lowest + threshold * 4)
		return (GRADIENT_4);
	if (z >=  data.map->lowest + threshold * 3)
		return (GRADIENT_3);
	if (z >=  data.map->lowest + threshold * 2)
		return (GRADIENT_2);
	if (z >=  data.map->lowest + threshold * 1)
		return (GRADIENT_1);
	if (z >=  data.map->lowest + threshold * 0)
		return (GRADIENT_0);
	return (WHITE);
}

void	put_pixel(t_data data, t_pos pos)
{
	char	*pixel;
	int		offset;

	if (pos.x > data.width - 1
		|| pos.y > data.height - 1)
		return ;
	if (pos.x < 0 || pos.y < 0)
		return ;
	offset = (pos.y * data.img->line_length + pos.x
			* (data.img->bits_per_pixel / 8));
	pixel = data.img->addr + offset;
	*(unsigned int *)pixel = get_color(data, pos.old_z);
}

void	transform_points(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			transform_pos(data, data->map->pos[y][x]);
			x++;
		}
		y++;
	}
}

void	draw_lines(t_data data)
{
	int		x;
	int		y;
	t_pos	***pos;

	y = 0;
	pos = data.map->pos;
	while (y < data.map->height)
	{
		x = 0;
		while (x < data.map->width)
		{
			if (x + 1 < data.map->width)
				draw_line(data, *pos[y][x], *pos[y][x + 1]);
			if (y + 1 < data.map->height)
				draw_line(data, *pos[y][x], *pos[y + 1][x]);
			x++;
		}
		y++;
	}
}
