/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 06:19:45 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *file)
{
	int		fd;
	char	buffer[1];

	if (ft_strlen(file) < 4)
		exit_args();
	if (ft_strcmp(".fdf", file + ft_strlen(file) - 4))
		exit_args();
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		close (fd);
		exit_error("The file does not exist");
	}
	if (read(fd, 0, 0) < 0)
	{
		close (fd);
		exit_error("The file cannot be read");
	}
	if (read(fd, buffer, 1) < 1)
	{
		close (fd);
		exit_error("The file is empty");
	}
	close (fd);
}

static void	*get_map_size(t_map **map, t_list *lines)
{
	size_t	width;
	size_t	height;
	t_list	*current;

	width = ft_countwords(lines->content, " \n");
	height = 0;
	current = lines;
	while (current)
	{
		if (width != ft_countwords(current->content, " \n"))
		{
			ft_lstclear(&lines, free);
			exit_error("Please give a rectangular map with numeric values");
		}
		height++;
		current = current->next;
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
	int		**tab;
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

static void	*get_map_pos(t_map **map)
{
	int		y;
	int		x;
	t_pos	***pos;

	pos = malloc((*map)->height * sizeof(t_pos **));
	if (!pos)
		return (NULL);
	y = 0;
	while (y < (*map)->height)
	{
		pos[y] = malloc((*map)->width * sizeof(t_pos *));
		if (!pos[y])
			return (free_2d((void **)pos, y));
		x = 0;
		while (x < (*map)->width)
		{
			pos[y][x] = ft_newpos(x, y, (*map)->tab[y][x]);
			if (!pos[y][x])
				return (free_2d((void **)pos[y], x), free_2d((void **)pos, y));
			x++;
		}
		y++;
	}
	(*map)->pos = pos;
	return (map);
}

t_map	*get_map(char *file)
{
	t_map	*map;
	t_list	*lines;

	map = NULL;
	lines = get_lines(file);
	if (!lines || !get_map_size(&map, lines))
	{
		ft_lstclear(&lines, free);
		exit_error("An allocation failed");
	}
	map->tab = NULL;
	map->pos = NULL;
	if (!get_map_tab(&map, lines) || !get_map_pos(&map))
	{
		ft_lstclear(&lines, free);
		free_map(map);
		exit_error("An allocation failed");
	}
	map->highest = get_highest_pos(map);
	map->lowest = get_lowest_pos(map);
	ft_lstclear(&lines, free);
	return (map);
}
