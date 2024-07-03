/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 16:57:05 by nbellila         ###   ########.fr       */
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
		free_data(data);
		exit_error("An allocation failed");
	}
	draw_points(data);
	show_pos(map);
	ft_printf("height : %d, width : %d\n", data->map->height, data->map->width);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	exit_success(data);
}
