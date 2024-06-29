/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:09:26 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/29 19:42:53 by nbellila         ###   ########.fr       */
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
	ft_putendl_fd("An allocation failed", 2);
	exit(EXIT_FAILURE);
}