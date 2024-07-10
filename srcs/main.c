/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 06:09:56 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*data;

	if (argc != 2)
		exit_args();
	check_file(argv[1]);
	map = get_map(argv[1]);
	data = init_data(map);
	if (!data || !init_mlx(data))
	{
		free_map(map);
		free_data(data);
		exit_error("An allocation failed");
	}
	transform_points(data);
	draw_lines(*data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	show_inputs(*data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_loop(data->mlx);
	exit_success(data);
}
