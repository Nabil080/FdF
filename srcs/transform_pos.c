/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 18:59:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_pos *pos)
{
	int	old_x;

	old_x = pos->x;
	pos->x = (old_x - pos->y) * cos(0.523599);
	pos->y = (old_x + pos->y) * sin(0.523599) - pos->z;
}

static void	center(t_data *data, t_pos *pos)
{
	pos->x += (data->width / 2);
	pos->y += (data->height / 2);
	pos->x -= ((data->map->width - 1) * data->zoom) / 2;
	pos->y -= ((data->map->height - 1) * data->zoom) / 2;
}

static void	translate(t_data *data, t_pos *pos)
{
	pos->x += (data->width / 2) + data->x;
	pos->y += data->y;
}

static void	rotate_xyz(t_data *data, t_pos *pos)
{
	int	old_y;
	int	old_x;

	old_y = pos->y;
	pos->y = old_y * cos(data->alpha) - pos->z * sin(data->alpha);
	pos->z = old_y * sin(data->alpha) + pos->z * cos(data->alpha);
	old_x = pos->x;
	pos->x = old_x * cos(data->tetha) + pos->z * sin(data->tetha);
	pos->z = pos->z * cos(data->tetha) - old_x * sin(data->tetha);
	old_x = pos->x;
	pos->x = old_x * cos(data->gamma) - pos->y * sin(data->gamma);
	pos->y = old_x * sin(data->gamma) + pos->y * cos(data->gamma);
}

void	transform_pos(t_data *data, t_pos *pos)
{
	pos->x *= data->zoom;
	pos->y *= data->zoom;
	pos->z *= data->zoom;
	center(data, pos);
	if (data->projection == ISO)
		iso(pos);
	rotate_xyz(data, pos);
	translate(data, pos);
	return ;
}
