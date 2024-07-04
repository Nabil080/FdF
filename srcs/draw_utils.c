/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:10:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/04 20:31:06 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vars	get_bresenham_vars(t_pos a, t_pos b, int isLow)
{
	t_vars	vars;

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

static void	bresenham_low_slope(t_data *data, t_pos a, t_pos b)
{
	t_pos	current;
	t_vars	vars;

	vars = get_bresenham_vars(a, b, 1);
	current = a;
	while (current.x < b.x)
	{
		if (b.x - current.x <= (b.x - a.x) / 2)
			current.z = b.z;
		put_pixel(data, &current, 0);
		if (vars.d > 0)
		{
			current.y += vars.i;
			vars.d = vars.d + (2 * (vars.dy - vars.dx));
		}
		else
			vars.d = vars.d + 2 * vars.dy;
		current.x++;
	}
}

static void	bresenham_high_slope(t_data *data, t_pos a, t_pos b)
{
	t_pos	current;
	t_vars	vars;

	vars = get_bresenham_vars(a, b, 0);
	current = a;
	while (current.y < b.y)
	{
		if (b.y - current.y <= (b.y - a.y) / 2)
			current.z = b.z;
		put_pixel(data, &current, 0);
		if (vars.d > 0)
		{
			current.x += vars.i;
			vars.d = vars.d + (2 * (vars.dx - vars.dy));
		}
		else
			vars.d = vars.d + 2 * vars.dx;
		current.y++;
	}
}

void	draw_line(t_data *data, t_pos a, t_pos b)
{
	t_pos	tmp;

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
