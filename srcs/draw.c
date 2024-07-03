/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 20:42:36 by nbellila         ###   ########.fr       */
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
	if (0)
		iso(&pos->x, &pos->y, pos->z);
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
static void	bresenham_low_slope(t_data *data, t_pos a, t_pos b)
{
	t_pos	current;
	int	dx;
	int	dy;
	int	yi;
	int	d;
	
	dx = b.x - a.x;
	dy = b.y - a.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	current.x = a.x;
	current.y = a.y;
	current.z = a.z;
	while (current.x < b.x)
	{
		if (b.x - current.x <= (b.x - a.x) / 2)
			current.z = b.z;
		put_pixel(data, &current, 0);
		if (d > 0)
		{
			current.y += yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		current.x++;
	}
}

void	bresenham_high_slope(t_data *data, t_pos a, t_pos b)
{
	t_pos	current;
	int	dx;
	int	dy;
	int	xi;
	int	d;
	
	dx = b.x - a.x;
	dy = b.y - a.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	current.x = a.x;
	current.y = a.y;
	current.z = a.z;
	while (current.y < b.y)
	{
		if (b.y - current.y <= (b.y - a.y) / 2)
			current.z = b.z;
		put_pixel(data, &current, 0);
		if (d > 0)
		{
			current.x += xi;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + 2 * dx;
		current.y++;
	}
}

static void	draw_line(t_data *data, t_pos a, t_pos b)
{
	t_pos	x;
	t_pos	y;

	x = a;
	y = b;
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			x = b;
			y = b;
		}
		bresenham_low_slope(data, x, y);
	}
	else
	{
		if (a.y > b.y)
		{
			x = b;
			y = b;
		}
		bresenham_high_slope(data, x, y);
	}
}
