/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 03:02:29 by nbellila         ###   ########.fr       */
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
static void	*get_map_size(t_map **map, t_list *lines)
{
	size_t	width;
	size_t	height;

	width = ft_countwords(lines->content, " \n");
	height = 0;
	while (lines)
	{
		if (width != ft_countwords(lines->content, " \n"))
			return (NULL);
		height++;
		lines = lines->next;
	}
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (NULL);
	(*map)->height = height;
	(*map)->width = width;
	return (*map);
}

static void	*get_map_tab(t_map **map, t_list *lines)
{
	int	**tab;
	size_t	row;

	tab = malloc((*map)->height * sizeof(int *));
	if (!tab)
		return (NULL);
	row = 0;
	while (lines)
	{
		tab[row] = ft_splittoi(lines->content, " \n");
		if (!tab[row])
			return (free_2d((void **)tab, row));
		row++;
		lines = lines->next;
	}
	(*map)->tab = tab;
	return (*map);
}

t_map	*get_map(char *file)
{
	t_map	*map;
	t_list	*lines;

	map = NULL;
	lines = get_lines(file);
	if (!lines)
		exit_malloc();
	if (!get_map_size(&map, lines))
	{
		ft_lstclear(&lines, free);
		exit_args();
	}
	if (!get_map_tab(&map, lines))
	{
		ft_lstclear(&lines, free);
		free(map);
		exit_malloc();
	}
	ft_lstclear(&lines, free);
	return (map);
}
