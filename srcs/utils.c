/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 02:34:51 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	show_input(t_data data, char *str)
{
	static int	y = 20;

	if (!str)
	{
		y = 20;
		return ;
	}
	mlx_string_put(data.mlx, data.win, 10, y, ORANGE, str);
	y += 20;
}

void	show_inputs(t_data data)
{
	show_input(data, "Exit : Escape");
	show_input(data, "Reset : Spacebar");
	show_input(data, "Zoom : Mouse wheel");
	show_input(data, "Move : W(up) A(left) S(down) D(right)");
	show_input(data, "Rotate axis : Z(x) X(y) V(z)");
	show_input(data, "Projection iso : 0");
	show_input(data, "Projection ortho : 1(top), 2(front), 3(right side)");
	show_input(data, NULL);
}

int	get_lowest_pos(t_map *map)
{
	int	x;
	int	y;
	int	lowest;

	lowest = map->pos[0][0]->old_z;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->pos[y][x]->old_z < lowest)
				lowest = map->pos[y][x]->old_z;
			x++;
		}
		y++;
	}
	return (lowest);
}

int	get_highest_pos(t_map *map)
{
	int	x;
	int	y;
	int	highest;

	highest = map->pos[0][0]->old_z;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->pos[y][x]->old_z > highest)
				highest = map->pos[y][x]->old_z;
			x++;
		}
		y++;
	}
	return (highest);
}

t_pos	*ft_newpos(int x, int y, int z)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->x = x;
	pos->y = y;
	pos->z = z;
	pos->old_z = z;
	return (pos);
}
