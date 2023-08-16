/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:07:45 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 14:45:41 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_get_z_min_andmax(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->z_min = map->array[0][0][0];
	map->z_max = map->array[0][0][0];
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->array[i][j][0] < map->z_min)
				map->z_min = map->array[i][j][0];
			if (map->array[i][j][0] > map->z_max)
				map->z_max = map->array[i][j][0];
			j++;
		}
		i++;
	}
}

static void	allocate_map_array(t_map *map)
{
	map->array = malloc(sizeof(int **) * map->height);
	if (!map->array)
		ft_return_error("malloc error", 1);
}

static void	fill_map_array(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < map->height)
	{
		if (get_next_line(fd, &line) <= 0 || *line == '\0')
			ft_return_error("irregular height", 0);
		map->array[i] = malloc(sizeof(int *) * map->width);
		if (!map->array[i])
			ft_return_error("error in malloc", 1);
		fill(map->array[i], line, map->width);
		free(line);
		i++;
	}
}

void	ft_check_valid(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	map->width = ft_get_width(filename);
	map->height = ft_get_height(filename);
	allocate_map_array(map);
	fill_map_array(map, fd);
	ft_get_z_min_andmax(map);
	if (close(fd) == -1)
		ft_return_error("error", 1);
}
