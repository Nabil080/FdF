/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:03 by nbellila          #+#    #+#             */
/*   Updated: 2024/06/24 23:24:34 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		exit_arguments();
	if (ft_strlen(argv[1]) < 4)
		exit_arguments();
	if (ft_strcmp(".fdf", argv[1] + ft_strlen(argv[1]) - 4))
		exit_arguments();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_arguments();
	close (fd);
}

t_map	*get_map(int fd)
{
	t_map	*map;
	t_list	*lst;
	t_list	*new;
	char	*line;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_failure();
	lst = malloc (sizeof(t_list));
	if (!lst)
		exit_free(map);
	lst = NULL;
	line = get_next_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			exit_failure();
		ft_lstadd_back(&lst, new);
		line = get_next_line(fd);
	}
	map->height = ft_lstsize(lst);
	map->lines = lst;
	return (map);
}

void	show_map(t_map *map)
{
	t_list	*line;

	line = map->lines;
	while (line)
	{
		ft_printf("%s", ft_lsttos(line));
		line = line->next;
	}
}