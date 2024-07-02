/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 05:24:40 by nbellila         ###   ########.fr       */
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
	if (!init_mlx(data))
	{
		free_data(data);
		exit_error("An allocation failed");
	}
	show_map(map);
	// mlx_loop(data->mlx);
	exit_success(data);
}
