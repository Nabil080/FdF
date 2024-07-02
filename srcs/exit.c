/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:09:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 04:05:56 by nbellila         ###   ########.fr       */
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

void	exit_malloc(void)
{
	exit_error("An allocation failed");
}

void	exit_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	exit_success(t_map *map)
{
	free_2d((void **)map->tab, map->height);
	free(map);
	exit(EXIT_SUCCESS);
}