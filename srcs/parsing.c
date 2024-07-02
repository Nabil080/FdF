/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/02 04:09:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file(char *file)
{
	int		fd;
	char buffer[1];

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
	{
		ft_lstclear(&lines, free);
		exit_error("An allocation failed");
	}
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
		exit_error("Please give a rectangular map with numeric values");
	}
	if (!get_map_tab(&map, lines))
	{
		ft_lstclear(&lines, free);
		free(map);
		exit_error("An allocation failed");
	}
	ft_lstclear(&lines, free);
	return (map);
}
