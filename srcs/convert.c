/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/07 19:10:21 by nbellila         ###   ########.fr       */
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
	pos->y +=  + data->y;
}

void	transform_pos(t_data *data, t_pos *pos)
{
	zoom(data, pos);
	center(data, pos);
	iso(data, pos);
	translate(data, pos);
	return ;
}
