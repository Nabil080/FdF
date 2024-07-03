/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 18:58:42 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*window*/
# define TITLE "Filu de Feru"
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define DEFAULT_ZOOM 1
/*keys*/
# define Q 113
# define ESC 65307
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
	t_map	*map;
	void	*mlx;
	void	*win;
	t_img	*img;
	int		width;
	int		height;
	int		zoom;
}t_data;

#endif