/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:10:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 10:04:59 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vars get_bresenham_vars(t_pos a, t_pos b, int isLow)
{
	t_vars vars;

	vars.threshold = abs(b.y - a.y) / (abs(b.old_z - a.old_z) + 1);
	vars.iteration = 0;
	vars.z_diff = 1;
	if (b.z < a.old_z)
		vars.z_diff = -1;
	vars.dx = b.x - a.x;
	vars.dy = b.y - a.y;
	vars.i = 1;
	if (isLow && vars.dy < 0)
	{
		vars.i = -1;
		vars.dy = -vars.dy;
	}
	if (!isLow && vars.dx < 0)
	{
		vars.i = -1;
		vars.dx = -vars.dx;
	}
	vars.d = 2 * vars.dx - vars.dy;
	return (vars);
}

static void bresenham_low_slope(t_data data, t_pos a, t_pos b)
{
	t_pos  current;
	t_vars vars;

	vars = get_bresenham_vars(a, b, 1);
	current = a;
	while (current.x < b.x)
	{
		put_pixel(data, current);
		if (vars.d > 0)
		{
			current.y += vars.i;
			vars.d = vars.d + (2 * (vars.dy - vars.dx));
		}
		else
			vars.d = vars.d + 2 * vars.dy;
		current.x++;
		if (vars.iteration == vars.threshold)
		{
			vars.iteration = 0;
			current.old_z += vars.z_diff;
		}
		else
			vars.iteration++;
	}
}

static void bresenham_high_slope(t_data data, t_pos a, t_pos b)
{
	t_pos  current;
	t_vars vars;

	vars = get_bresenham_vars(a, b, 0);
	current = a;
	while (current.y < b.y)
	{
		put_pixel(data, current);
		if (vars.d > 0)
		{
			current.x += vars.i;
			vars.d = vars.d + (2 * (vars.dx - vars.dy));
		}
		else
			vars.d = vars.d + 2 * vars.dx;
		current.y++;
		if (vars.iteration == vars.threshold)
		{
			vars.iteration = 0;
			current.old_z += vars.z_diff;
		}
		else
			vars.iteration++;
	}
}

void draw_line(t_data data, t_pos a, t_pos b)
{
	t_pos tmp;

	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		bresenham_low_slope(data, a, b);
	}
	else
	{
		if (a.y > b.y)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		bresenham_high_slope(data, a, b);
	}
}
