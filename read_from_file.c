/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:16:34 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:12:45 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (height);
}

int	count_width(char *line)
{
	int	width;

	width = 0;
	while (*line)
	{
		if (*line != ' ')
		{
			width++;
			while (*line && *line != ' ')
				line++;
		}
		else
			line++;
	}
	return (width);
}

int	ft_get_width(char *filename)
{
	int		fd;
	char	*line;
	char	*tmp_line;
	int		width;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_return_error("open error", 1);
	if (get_next_line(fd, &line) <= 0)
		ft_return_error("invalid map (empty)", 0);
	width = count_width(line);
	free(line);
	while (get_next_line(fd, &tmp_line))
		free(tmp_line);
	if (close(fd) == -1)
		ft_return_error("close error", 1);
	return (width);
}

void	fill(int **n, char *line, int width)
{
	char	**split_line;
	int		i;

	i = 0;
	split_line = ft_split(line, ' ');
	while (split_line[i] && i < width)
	{
		n[i] = malloc(sizeof(int) * 2);
		if (!n[i])
			ft_return_error("error with malloc", 1);
		n[i][0] = ft_atoi(split_line[i]);
		n[i][1] = -1;
		if (ft_strchr(split_line[i], ','))
			n[i][1] = ft_atoi_base(ft_strchr(split_line[i], ',')
					+ 1, "0123456789ABCDEF");
		free(split_line[i]);
		i++;
	}
	if (i != width || split_line[i])
		ft_return_error("error: irregular width", 0);
	free(split_line);
}
