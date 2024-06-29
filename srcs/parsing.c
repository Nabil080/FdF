/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/29 19:25:30 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		exit_args();
	if (ft_strlen(argv[1]) < 4)
		exit_args();
	if (ft_strcmp(".fdf", argv[1] + ft_strlen(argv[1]) - 4))
		exit_args();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_args();
	close (fd);
}

t_map	*get_map(char *file)
{
	t_map	*map;
	t_list	*lines;

	// recupere les lignes en liste chainee
	lines = get_lines(file);
	if (!lines)
		return (NULL);
	ft_putlst(lines);
	// todo : verifie que la map est valide
	// if (!check_map(lines));
		// todo : sinon free lines et return
			// return (ft_lstclear(&lines, free))
	map = malloc(sizeof(map));
	// todo : get map data (height, width, int**)
	// lst_to_map(lines);
	ft_lstclear(&lines, free);
	return (map);
}
