/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:25:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 21:43:36 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	manage_translate(int keycode, t_data *data);

static void	manage_rotate(int keycode, t_data *data);

static void	manage_projection(int keycode, t_data *data);

int	key_hook(int keycode, t_data *data)
{
	if (keycode == EXIT_KEY)
		mlx_loop_end(data->mlx);
	if (keycode == RESET_KEY)
		reset_img(data);
	manage_translate(keycode, data);
	manage_rotate(keycode, data);
	manage_projection(keycode, data);
	if (!redraw_img(data))
	{
		free_map(data->map);
		free_data(data);
		exit_error("An allocation failed");
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->zoom += 2;
	if (button == 5 && data->zoom > 2)
		data->zoom -= 2;
	redraw_img(data);
	x++;
	y++;
	return (0);
}

static void	manage_translate(int keycode, t_data *data)
{
	if (keycode == 'w')
		data->y += TRANSLATE_INCREMENT;
	if (keycode == 'a')
		data->x += TRANSLATE_INCREMENT;
	if (keycode == 's')
		data->y -= TRANSLATE_INCREMENT;
	if (keycode == 'd')
		data->x -= TRANSLATE_INCREMENT;
}

static void	manage_rotate(int keycode, t_data *data)
{
	if (keycode == 'z')
		data->alpha += ANGLE_INCREMENT;
	if (keycode == 'x')
		data->tetha += ANGLE_INCREMENT;
	if (keycode == 'v')
		data->gamma += ANGLE_INCREMENT;
}

static void	manage_projection(int keycode, t_data *data)
{
	if (keycode == ISO_VIEW)
		data->projection = ISO;
	if (keycode == TOP_VIEW || keycode == FRONT_VIEW || keycode == SIDE_VIEW)
	{
		data->projection = ORTHO;
		data->alpha = 0;
		data->tetha = 0;
		data->gamma = 0;
	}
	if (keycode == FRONT_VIEW)
		data->alpha = 1.60;
	if (keycode == SIDE_VIEW)
	{
		data->tetha = 1.60;
		data->gamma = -1.60;
	}
}
