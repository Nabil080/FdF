/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:25:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 08:34:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	manage_zoom(int keycode, t_data *data);

static void	manage_translate(int keycode, t_data *data);

static void	manage_rotate(int keycode, t_data *data);

static void	manage_projection(int keycode, t_data *data);

int	key_hook(int keycode, t_data *data)
{
	if (keycode == EXIT_KEY)
		mlx_loop_end(data->mlx);
	if (keycode == RESET_KEY)
		reset_img(data);
	if (keycode == ENTER || keycode == ENTER_PAD)
		data->inputs *= -1;
	if (keycode == 'c')
		data->gradient++;
	manage_zoom(keycode, data);
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

static void	manage_zoom(int keycode, t_data *data)
{
	if (keycode == PLUS)
		data->zoom += 1;
	if (keycode == MINUS && data->zoom > 1)
		data->zoom -= 1;
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
	if (keycode == ONE)
		data->alpha -= ANGLE_INCREMENT;
	if (keycode == THREE)
		data->alpha += ANGLE_INCREMENT;
	if (keycode == FOUR)
		data->tetha -= ANGLE_INCREMENT;
	if (keycode == SIX)
		data->tetha += ANGLE_INCREMENT;
	if (keycode == SEVEN)
		data->gamma -= ANGLE_INCREMENT;
	if (keycode == NINE)
		data->gamma += ANGLE_INCREMENT;
}

static void	manage_projection(int keycode, t_data *data)
{
	if (keycode == ISO_VIEW)
		reset_img(data);
	if (keycode == TOP_VIEW || keycode == FRONT_VIEW || keycode == SIDE_VIEW)
	{
		data->projection = ORTHO;
		data->y = 0;
		data->alpha = 0;
		data->tetha = 0;
		data->gamma = 0;
	}
	if (keycode == FRONT_VIEW || keycode == SIDE_VIEW)
		data->y = data->zoom * data->map->highest
			+ data->zoom * data->map->height;
	if (keycode == FRONT_VIEW)
		data->alpha = 1.60;
	if (keycode == SIDE_VIEW)
	{
		data->tetha = 1.60;
		data->gamma = -1.60;
	}
}
