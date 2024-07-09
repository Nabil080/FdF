/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 21:45:55 by nbellila         ###   ########.fr       */
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
	mlx_string_put(data.mlx, data.win, 10, y, GREEN, str);
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

static int	get_color(int z)
{
	int	color;

	color = WHITE;
	if (z > 0)
		color = (GREEN);
	if (z < 0)
		color = (BLUE);
	return (color);
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
	pos->color = get_color(z);
	return (pos);
}
