/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 18:44:04 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (pos.z > 0)
		*(unsigned int *)pixel = GREEN;
	else
		*(unsigned int *)pixel = WHITE;
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
