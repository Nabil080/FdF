/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/08 19:58:31 by nbellila         ###   ########.fr       */
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
# define GREEN 0x0000FF00
# define WHITE 0xFFFFFFFF

/*structs*/
typedef struct s_pos{
	int	x;
	int	y;
	int	z;
}t_pos;

typedef struct s_map{
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