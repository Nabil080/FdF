/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:26:19 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/24 00:44:27 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_data	*init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_failure();
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_free(data);
	data->window = mlx_new_window(data->mlx, 1000, 1000, "Filu de Feru");
	mlx_key_hook(data->window, handle_input, data);
	mlx_mouse_hook(data->window, handle_mouse, data);
	return (data);
}

static void	get_map(t_list **map, char **argv)
{
	int		fd;
	char	*line;
	size_t	width;
	size_t	height;
	t_list	*new;

	*map = malloc(sizeof(t_list));
	if (!*map)
		exit_failure();
	*map = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	width = ft_strlen(line);
	height = 0;
	while (line)
	{
		height++;
		if (ft_strlen(line) != width)
			exit_failure();
		new = ft_lstnew(line);
		if (!new)
			exit_failure();
		ft_lstadd_back(map, new);
		line = get_next_line(fd);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_list	*map;

	if (argc != 2)
		exit_arguments();
	map = NULL;
	get_map(&map, argv);
	while (map)
	{
		ft_printf("%s", ft_lsttos(map));
		map = map->next;
	}
	data = init();
	mlx_loop(data->mlx);
	return (0);
}