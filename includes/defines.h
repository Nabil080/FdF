/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 02:34:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*window*/
# define TITLE "Filu de Feru"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
/*INCREMENTS*/
# define TRANSLATE_INCREMENT 50
# define ANGLE_INCREMENT 0.1
/*keys*/
# define ESC 65307
# define ISO_VIEW 65438
# define TOP_VIEW 65436
# define FRONT_VIEW 65433
# define SIDE_VIEW 65435
# define EXIT_KEY ESC
# define RESET_KEY ' '
/*projections*/
# define ISO 0
# define ORTHO 1
/*colors*/
# define WHITE 0xFFFFFFFF
# define ORANGE 0xFFFFA500
# define GRADIENT_0 0xFF292f56
# define GRADIENT_1 0xFF1e4572
# define GRADIENT_2 0xFF005c8b
# define GRADIENT_3 0xFF007498
# define GRADIENT_4 0xFF008ba0
# define GRADIENT_5 0xFF00a3a4
# define GRADIENT_6 0xFF00bca1
# define GRADIENT_7 0xFF00d493
# define GRADIENT_8 0xFF69e882
# define GRADIENT_9 0xFFacfa70

/*structs*/
typedef struct s_pos{
	int	x;
	int	y;
	int	z;
	int	old_z;
}t_pos;

typedef struct s_map{
	int		highest;
	int		lowest;
	int		height;
	int		width;
	int		**tab;
	t_pos	***pos;
}t_map;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct t_data{
	t_map		*map;
	void		*mlx;
	void		*win;
	t_img		*img;
	int			width;
	int			height;
	int			zoom;
	int			x;
	int			y;
	double		alpha;
	double		gamma;
	double		tetha;
	int			projection;
}t_data;

typedef struct s_bresenham{
	int	dx;
	int	dy;
	int	i;
	int	d;
}t_vars;

#endif