/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 04:59:25 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/07 18:14:47 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->img = malloc(sizeof(t_img));
	if (!data->img)
	{
		free(data);
		return (NULL);
	}
	data->map = map;
	data->height = WINDOW_HEIGHT;
	data->width = WINDOW_WIDTH;
	if (data->map->width > data->map->height)
		data->spacing = data->width / (data->map->width);
	else
		data->spacing = data->height / (data->map->height);
	data->zoom = DEFAULT_ZOOM;
	data->mlx = NULL;
	data->win = NULL;
	data->x = 0;
	data->y = 0;
	return (data);
}

void	*init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data->img), NULL);
	data->img->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		return (NULL);
	data->win = mlx_new_window(data->mlx, data->width, data->height, TITLE);
	if (!data->win)
		return (NULL);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length,
			&data->img->endian);
	if (!data->img->addr)
		return (NULL);
	return (data);
}
