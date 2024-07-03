/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 06:38:08 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 15:19:32 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	center(data, &x, &y);
	offset = (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	pixel = data->img->addr + offset;
	*(unsigned int *)pixel = color;
}

static void	bresenham_right(t_data *data, int x, int y)
{
	int	x2;
	int	y2;
	int	p;
	int	dx;
	int	dy;

	x2 = x + 1 * get_spacing(data);
	y2 = y * get_spacing(data);
	ft_printf("x: %d, y: %d, x2: %d, y2: %d\n", x, y, x2, y2);
	dx = x2 - x;  
    dy = y2 - y;  
    p = 2 * dy - dx;  
    while(x < x2)  
    {  
		ft_printf("SENT (x:%d, y:%d)\n", x, y);
        if(p >= 0)  
        {
            my_mlx_pixel_put(data, x, y, WHITE);
            y = y + 1;  
            p = p + 2 * dy - 2 * dx;  
        }  
        else  
        {  
            my_mlx_pixel_put(data, x, y, WHITE);
            p = p + 2 * dy;
		}
		x = x + 1;  
	}
}
/* Draws the bottom and right lines of a point */
static void	draw_lines(t_data *data, int x, int y)
{
	if (x + 1 < data->map->width)
		bresenham_right(data, x, y);
	if (y + 1 < data->map->height)
		return ;
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;
	int	spacing;

	spacing = get_spacing(data);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->tab[y][x] == 0)
				my_mlx_pixel_put(data, x * spacing, y * spacing, WHITE);
			else
				my_mlx_pixel_put(data, x * spacing, y * spacing, GREEN);
			if (0)
				draw_lines(data, x, y);
			x++;
		}
		y++;
	}
}