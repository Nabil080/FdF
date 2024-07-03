/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:09:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 18:28:39 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_args(void)
{
	ft_putendl_fd("Please give a valid .fdf file as argument", 2);
	ft_putendl_fd("Correct format:./fdf <model>", 2);
	ft_putendl_fd("Example :./fdf 42.fdf", 2);
	exit(EXIT_FAILURE);
}

void	exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	exit_success(t_data *data)
{
	free_map(data->map);
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	free_data(t_data *data)
{
	ft_printf("free data\n");
	if (!data)
		return ;
	ft_printf("free mlx\n");
	if (!data->mlx)
		return (free(data));
	ft_printf("destroy window\n");
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
	{
	ft_printf("destroy && free image\n");
		mlx_destroy_image(data->mlx, data->img->img);
		free(data->img);
	}
	ft_printf("destroy display\n");
	mlx_destroy_display(data->mlx);
	ft_printf("free mlx && data\n");
	free(data->mlx);
	free(data);
}

void	free_map(t_map *map)
{
	int	x;
	int	y;

	if (map->tab)
		free_2d((void **)map->tab, map->height);
	if (!map->pos)
	{
		free(map);
		return ;
	}
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			free(map->pos[y][x]);
			x++;
		}
		free(map->pos[y]);
		y++;
	}
	free(map->pos);
	free(map);
}
