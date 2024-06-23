/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 22:35:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/23 23:44:06 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "defines.h"

typedef	struct s_data
{
	void	*mlx;
	void	*window;
}			t_data;
/*
* exit
*/
void	exit_failure(void);

void	exit_free(void *data);

void	exit_free_all(t_data *data);
/*
* handler
*/
int	handle_mouse(int button, int x, int y, void *param);

int	handle_input(int key, void *param);

#endif