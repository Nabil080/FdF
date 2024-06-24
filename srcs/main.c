/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:26:19 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/24 23:24:38 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*init(t_map *map)
{
	t_data	*data;
	size_t	width;
	size_t	height;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_failure();
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_free(data);
	data->map = map;
	width = map->width * 30;
	height = map->height * 30;
	data->window = mlx_new_window(data->mlx, width, height, "Filu de Feru");
	mlx_key_hook(data->window, handle_input, data);
	mlx_mouse_hook(data->window, handle_mouse, data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;
	int		fd;

	check_args(argc, argv);
	fd = open(argv[1], O_RDONLY);
	map = get_map(fd);
	data = init(map);
	show_map(map);
	mlx_loop(data->mlx);
	return (0);
}