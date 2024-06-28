/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/28 18:41:53 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		exit_args();
	if (ft_strlen(argv[1]) < 4)
		exit_args();
	if (ft_strcmp(".fdf", argv[1] + ft_strlen(argv[1]) - 4))
		exit_args();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_args();
	close (fd);
}
