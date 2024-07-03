/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 19:30:17 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_data *data, t_pos a, t_pos b);

static void	put_pixel(t_data *data, t_pos *pos, int spacing)
{
	char	*pixel;
	int		color;
	int		offset;

	color = get_color(pos->z);
	if (spacing > 0)
	{
		pos->y *= spacing;
		pos->x *= spacing;
		center(data, pos, spacing);
	}
	offset = (pos->y * data->img->line_length + pos->x
			* (data->img->bits_per_pixel / 8));
	pixel = data->img->addr + offset;
	*(unsigned int *)pixel = color;
}

void	draw_points(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			put_pixel(data, data->map->pos[y][x], get_spacing(data));
			x++;
		}
		y++;
	}
}

void	draw_lines(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x + 1 < data->map->width)
				draw_line(data, *data->map->pos[y][x], *data->map->pos[y][x + 1]);
			if (y + 1 < data->map->height)
				draw_line(data, *data->map->pos[y][x], *data->map->pos[y + 1][x]);
			x++;
		}
		y++;
	}
}

static void	draw_line(t_data *data, t_pos a, t_pos b)
{
	t_pos current;

	current.x = a.x;
	current.y = a.y;
	current.z = a.z;
	while (current.x < b.x)
	{
		if (b.x - current.x > (b.x - current.x) / 2)
			current.z = b.z;
		current.x++;
		put_pixel(data, &current, 0);
	}
	while (current.y < b.y)
	{
		if (b.y - current.y > (b.y - current.y) / 2)
			current.z = b.z;
		current.y++;
		put_pixel(data, &current, 0);
	}
}