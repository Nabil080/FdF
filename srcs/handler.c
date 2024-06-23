/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:31:44 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/23 23:36:10 by nbellila         ###   ########.fr       */
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
	ft_printf("key : %d\n", key);
	(void)*param;
	return (1);
}