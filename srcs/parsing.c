/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/29 19:41:53 by nbellila         ###   ########.fr       */
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
static t_map	*get_size(t_list *lines)
{
	t_map	*map;
	size_t	width;
	size_t	height;

	width = ft_strlen(lines->content);
	height = 0;
	while (lines)
	{
		if (width != ft_strlen(lines->content))
			return (NULL);
		height++;
		lines = lines->next;
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = height;
	map->width = width;
	return (map);
}
t_map	*get_map(char *file)
{
	t_map	*map;
	t_list	*lines;

	// recupere les lignes en liste chainee
	lines = get_lines(file);
	if (!lines)
		exit_malloc();
	// verifie que la map est valide
	map = get_size(lines);
	// sinon free lines et return
	if (!map)
	{
		ft_lstclear(&lines, free);
		exit_args();
	}
	ft_putlst(lines);
	// todo : get map data (height, width, int**)
	// map = lst_to_map(lines);
	ft_lstclear(&lines, free);
	return (map);
}
