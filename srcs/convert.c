/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/07 21:30:18 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_data *data, t_pos *pos)
{
	int	old_x;

	old_x = pos->x;
	pos->x = (old_x - pos->y) * cos(ANGLE);
	pos->y = (old_x + pos->y) * sin(ANGLE) - (pos->z * data->spacing);
}

static void	zoom(t_data *data, t_pos *pos)
{
	pos->x *= data->spacing;
	pos->y *= data->spacing;
}

static void	center(t_data *data, t_pos *pos)
{
	pos->x += (data->width / 2);
	pos->y += (data->height / 2);
	pos->x -= ((data->map->width - 1) * data->spacing) / 2;
	pos->y -= ((data->map->height - 1) * data->spacing) / 2;
}

static void	translate(t_data *data, t_pos *pos)
{
	pos->x += (data->width / 2) + data->x;
	pos->y += data->y;
}

void	rotate_z(t_data *data, t_pos *pos)
{
	int	old_x;

	old_x = pos->x;
	pos->x = old_x * cos(data->gamma) - pos->y * sin(data->gamma);
	pos->y = old_x * sin(data->gamma) + pos->y * cos(data->gamma);
}

void	rotate_y(t_data *data, t_pos *pos)
{
	int	old_x;

	old_x = pos->x;
	pos->x = old_x * cos(data->tetha) + pos->z * sin(data->tetha);
	pos->z = pos->z * cos(data->tetha) - old_x * sin(data->tetha);
}

void	rotate_x(t_data *data, t_pos *pos)
{
	int	old_y;

	old_y = pos->y;
	pos->y = old_y * cos(data->alpha) - pos->z * sin(data->alpha);
	pos->z = old_y * sin(data->alpha) + pos->z * cos(data->alpha);
}

void	transform_pos(t_data *data, t_pos *pos)
{
	zoom(data, pos);
	center(data, pos);
	iso(data, pos);
	rotate_x(data, pos);
	rotate_y(data, pos);
	rotate_z(data, pos);
	translate(data, pos);
	return ;
}
