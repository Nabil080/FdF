/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:31:04 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/24 00:39:18 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_failure(void)
{
	exit(EXIT_FAILURE);
}

void	exit_free(void *data)
{
	free(data);
	exit_failure();
}

void	exit_free_all(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
	exit_free(data);
}

void	exit_arguments(void)
{
	ft_printf("Please give a valid .fdf file as argument\n");
	ft_printf("Correct format : ./fdf <model>");
	ft_printf("Exemple : ./fdf 42.fdf");
	exit_failure();
}