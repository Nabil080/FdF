/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:09:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 16:14:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z)
{
	if (z > 0)
		return (GREEN);
	return (WHITE);
}

int get_spacing(t_data *data)
{
	if (data->map->width > data->map->height)
		return ((data->width / (data->map->width)) * data->zoom);
	else
		return ((data->height / (data->map->height)) * data->zoom);
}

void	center(t_data *data, int spacing, int *x, int *y)
{
	if (data->map->height > data->map->width)
	{
		*x += (data->width - (data->map->width - 1) * spacing) / 2;
		*y += spacing / 2;
	}
	else if (data->map->width > data->map->height)
	{
		*x += spacing / 2;
		*y += (data->height - (data->map->height - 1) * spacing) / 2;
	}
	else
	{
		*x += (data->width - (data->map->width - 1) * spacing) / 2;
		*y += (data->height - (data->map->height - 1) * spacing) / 2;
	}
}
