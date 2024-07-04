/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/04 21:11:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z > 0)
		return (GREEN);
	return (WHITE);
}

int	get_spacing(t_data *data)
{
	if (data->map->width > data->map->height)
		return (data->width / (data->map->width));
	else
		return (data->height / (data->map->height));
}

void	center(t_data *data, t_pos *pos, int spacing)
{
	if (data->map->height > data->map->width)
	{
		pos->x += (data->width - (data->map->width - 1) * spacing) / 2;
		pos->y += spacing / 2;
	}
	else if (data->map->width > data->map->height)
	{
		pos->x += spacing / 2;
		pos->y += (data->height - (data->map->height - 1) * spacing) / 2;
	}
	else
	{
		pos->x += (data->width - (data->map->width - 1) * spacing) / 2;
		pos->y += (data->height - (data->map->height - 1) * spacing) / 2;
	}
}

void	iso(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(ANGLE);
	*y = (tmp_x + tmp_y) * sin(ANGLE) - z;
}
