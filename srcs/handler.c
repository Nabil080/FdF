/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:31:44 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/24 23:24:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_mouse(int button, int x, int y, void *param)
{
	t_data	*data;

	data = param;
	ft_printf("button : %d, x : %d, y : %d\n", button, x, y);
	mlx_pixel_put(data->mlx, data->window, x, y, GREEN);
	return (1);
}

int	handle_input(int key, void *param)
{
	t_data	*data;

	data = param;
	ft_printf("key : %d\n", key);
	if (key == Q || key == ESC)
		exit_free_all(data);
	else
		mlx_string_put(data->mlx, data->window, 20, 20, GREEN, (char *)&key);
	return (1);
}