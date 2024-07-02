/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:35:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 04:09:14 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "defines.h"

/*structs*/
typedef struct s_map{
	size_t	height;
	size_t	width;
	int		**tab;
}t_map;
/*parsing*/
void	check_file(char *file);

t_map	*get_map(char *file);
/*exit*/
void	exit_args(void);

void	exit_malloc(void);

void	exit_error(char *str);

void	exit_success(t_map *map);
/*debug*/
void	show_map(t_map *map);

#endif