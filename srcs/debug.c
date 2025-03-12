/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:15:11 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 17:17:13 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void show_map(t_map *map)
{
	int col;
	int row;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			ft_putnbr_fd(map->tab[row][col], 2);
			while (map->tab[row][col] < 100)
			{
				if (map->tab[row][col] == 0)
					map->tab[row][col]++;
				map->tab[row][col] *= 10;
				ft_putchar_fd(' ', 2);
			}
			ft_putchar_fd(' ', 2);
			col++;
		}
		ft_putchar_fd('\n', 2);
		row++;
	}
}

void show_pos(t_map *map)
{
	int	   col;
	int	   row;
	t_pos *pos;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			pos = map->pos[row][col];
			ft_printf("pos[%d][%d]: (x:%d, y:%d, z:%d)\n", row, col, pos->x, pos->y, pos->z);
			col++;
		}
		row++;
	}
}
