/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:41:41 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 10:04:29 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
#define DEFINES_H

/*window*/
#define TITLE				"Filu de Feru"
#define WINDOW_WIDTH		1000
#define WINDOW_HEIGHT		1000
/*INCREMENTS*/
#define TRANSLATE_INCREMENT 50
#define ANGLE_INCREMENT		0.1
/*keys*/
#define ESC					65307
#define ENTER				65293
#define ENTER_PAD			65421
#define ONE					65436
#define THREE				65435
#define FOUR				65430
#define SIX					65432
#define SEVEN				65429
#define NINE				65434
#define PLUS				65451
#define MINUS				65453
#define ISO_VIEW			'i'
#define TOP_VIEW			't'
#define FRONT_VIEW			'f'
#define SIDE_VIEW			'r'
#define EXIT_KEY			ESC
#define RESET_KEY			' '
/*projections*/
#define ISO					0
#define ORTHO				1
/*colors*/
#define WHITE				0xFFFFFFFF
#define ORANGE				0xFFFFA500

#define GREEN_0				0xFF70c2db
#define GREEN_1				0xFF67cadb
#define GREEN_2				0xFF60d1d8
#define GREEN_3				0xFF5ed8d2
#define GREEN_4				0xFF61decb
#define GREEN_5				0xFF6ae4c1
#define GREEN_6				0xFF79e9b5
#define GREEN_7				0xFF8beea9
#define GREEN_8				0xFF9ff19c
#define GREEN_9				0xFFb6f490

#define RED_0				0xFFe4bcbf
#define RED_1				0xFFecb0b2
#define RED_2				0xFFf3a4a4
#define RED_3				0xFFf89894
#define RED_4				0xFFfc8d82
#define RED_5				0xFFfe816f
#define RED_6				0xFFfe765b
#define RED_7				0xFFfd6c45
#define RED_8				0xFFfa622b
#define RED_9				0xFFf55a00

#define BLUE_0				0xFF4b9b7f
#define BLUE_1				0xFF428f77
#define BLUE_2				0xFF39836f
#define BLUE_3				0xFF317666
#define BLUE_4				0xFF296b5e
#define BLUE_5				0xFF225f55
#define BLUE_6				0xFF1b544c
#define BLUE_7				0xFF154843
#define BLUE_8				0xFF0f3e3a
#define BLUE_9				0xFF0a3331

#define PURPLE_0			0xFFe37dd9
#define PURPLE_1			0xFFd16fca
#define PURPLE_2			0xFFbf62ba
#define PURPLE_3			0xFFae54ab
#define PURPLE_4			0xFF9c479c
#define PURPLE_5			0xFF8b3a8e
#define PURPLE_6			0xFF7b2d7f
#define PURPLE_7			0xFF6a2071
#define PURPLE_8			0xFF5b1263
#define PURPLE_9			0xFF4b0255

#define RANDOM_0			0xFFffffff
#define RANDOM_1			0xFFd4d5ba
#define RANDOM_2			0xFFeee6cd
#define RANDOM_3			0xFF99c637
#define RANDOM_4			0xFFced6ba
#define RANDOM_5			0xFF889d72
#define RANDOM_6			0xFFb5a18f
#define RANDOM_7			0xFFbcaead
#define RANDOM_8			0xFFb07a57
#define RANDOM_9			0xFF5ad88e

/*structs*/
typedef struct s_pos
{
		int x;
		int y;
		int z;
		int old_z;
} t_pos;

typedef struct s_map
{
		int		 highest;
		int		 lowest;
		int		 height;
		int		 width;
		int	   **tab;
		t_pos ***pos;
} t_map;

typedef struct s_img
{
		void *img;
		char *addr;
		int	  bits_per_pixel;
		int	  line_length;
		int	  endian;
} t_img;

typedef struct t_data
{
		t_map *map;
		void  *mlx;
		void  *win;
		t_img *img;
		int	   width;
		int	   height;
		int	   zoom;
		int	   x;
		int	   y;
		double alpha;
		double gamma;
		double tetha;
		int	   projection;
		int	   inputs;
		int	   gradient;
} t_data;

typedef struct s_bresenham
{
		int dx;
		int dy;
		int i;
		int d;
		int threshold;
		int iteration;
		int z_diff;
} t_vars;

#endif
