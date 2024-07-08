/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:54:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 17:26:50 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	show_inputs(t_data data)
{
	mlx_string_put(data.mlx, data.win, 10, 10, GREEN, "Zoom : Mouse wheel");
	mlx_string_put(data.mlx, data.win, 10, 30, GREEN, "Move : W A S D");
	mlx_string_put(data.mlx, data.win, 10, 50, GREEN, "Rotate : 0 1 2");
	mlx_string_put(data.mlx, data.win, 10, 70, GREEN, "Reset : Spacebar");
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
	return (pos);
}
