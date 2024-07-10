/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 04:59:25 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 05:52:50 by nbellila         ###   ########.fr       */
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
	data->projection = ISO;
	data->height = WINDOW_HEIGHT;
	data->width = WINDOW_WIDTH;
	data->mlx = NULL;
	data->win = NULL;
	data->inputs = -1;
	data->alpha = 0;
	data->gamma = 0;
	data->tetha = 0;
	data->x = 0;
	data->y = 0;
	data->zoom = get_default_zoom(data);
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

int	get_default_zoom(t_data *data)
{
	int	zoom;
	int	highest;
	int	lowest;

	highest = data->map->highest;
	lowest = data->map->lowest;
	if (data->map->width > data->map->height)
		zoom = (data->width / (data->map->width + (highest - lowest)));
	else
		zoom = (data->height / (data->map->height + (highest - lowest)));
	data->y = zoom * (highest) / 2;
	data->y += zoom * (lowest) / 2;
	return (zoom);
}
