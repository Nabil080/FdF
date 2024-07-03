/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 17:19:11 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
