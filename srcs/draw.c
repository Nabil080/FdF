/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 09:47:59 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int get_color(t_data data, int z)
{
	int threshold;
	int gradient[10];

	threshold = (data.map->highest - data.map->lowest) / 10 + 1;
	get_gradient(data, gradient);
	if (z >= data.map->highest)
		return (gradient[9]);
	if (z >= data.map->lowest + threshold * 8)
		return (gradient[8]);
	if (z >= data.map->lowest + threshold * 7)
		return (gradient[7]);
	if (z >= data.map->lowest + threshold * 6)
		return (gradient[6]);
	if (z >= data.map->lowest + threshold * 5)
		return (gradient[5]);
	if (z >= data.map->lowest + threshold * 4)
		return (gradient[4]);
	if (z >= data.map->lowest + threshold * 3)
		return (gradient[3]);
	if (z >= data.map->lowest + threshold * 2)
		return (gradient[2]);
	if (z >= data.map->lowest + threshold * 1)
		return (gradient[1]);
	return (gradient[0]);
}

void put_pixel(t_data data, t_pos pos)
{
	char *pixel;
	int	  offset;

	if (pos.x > data.width - 1 || pos.y > data.height - 1)
		return;
	if (pos.x < 0 || pos.y < 0)
		return;
	offset = (pos.y * data.img->line_length + pos.x * (data.img->bits_per_pixel / 8));
	pixel = data.img->addr + offset;
	*(unsigned int *)pixel = get_color(data, pos.old_z);
}

void transform_points(t_data *data)
{
	int x;
	int y;

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

void draw_lines(t_data data)
{
	int		 x;
	int		 y;
	t_pos ***pos;

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
