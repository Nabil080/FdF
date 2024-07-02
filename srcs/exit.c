/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:09:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 05:57:35 by nbellila         ###   ########.fr       */
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
	free_data(data);
	exit(EXIT_SUCCESS);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->map)
		free_map(data->map);
	if (!data->mlx)
		return (free(data));
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->adr)
		free(data->adr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

void	free_map(t_map *map)
{
	free_2d((void **)map->tab, map->height);
	free(map);
}