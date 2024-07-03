/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 06:22:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*window*/
# define SIZE 100
# define WIDTH 1920
# define HEIGHT 1080
# define TITLE "Filu de Feru"
/*keys*/
# define Q 113
# define ESC 65307
/*colors*/
# define GREEN 0x0000FF00
# define WHITE 0xFFFFFFFF

/*structs*/
typedef struct s_map{
	size_t	height;
	size_t	width;
	int		**tab;
}t_map;

typedef struct	s_img {
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
	void	*adr;
}t_data;


#endif