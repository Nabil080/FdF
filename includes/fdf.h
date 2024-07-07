/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:35:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/07 20:41:11 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "defines.h"

/*parsing*/
void	check_file(char *file);

t_map	*get_map(char *file);
/*exit*/
void	exit_args(void);

void	exit_error(char *str);

void	free_data(t_data *data);

void	exit_success(t_data *data);

void	free_map(t_map *map);
/*init*/
t_data	*init_data(t_map *map);

void	*init_mlx(t_data *data);

int	get_default_zoom(t_data *data);

int	get_highest_pos(t_map *map);
/*draw*/
void	put_pixel(t_data *data, t_pos *pos);

void	draw_points(t_data *data);

void	draw_lines(t_data *data);
/*draw utils*/
void	draw_line(t_data *data, t_pos a, t_pos b);
/*convert*/
int		get_color(int z);

void	transform_pos(t_data *data, t_pos *pos);
/*utils*/
t_pos	*ft_newpos(int x, int y, int z);
/*handler*/
int		key_hook(int keycode, t_data *data);

int		mouse_hook(int button, int x, int y, t_data *data);
/*debug*/
void	show_map(t_map *map);

void	show_pos(t_map *map);

#endif