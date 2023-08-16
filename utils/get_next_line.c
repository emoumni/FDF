/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:51:15 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 14:43:08 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	read_into_buffer(int fd, char *buf)
{
	int	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
	{
		return (-1);
	}
	return (ret);
}

static int	process_buffer(char **line, char *buf, int ret)
{
	int	i;

	i = 0;
	while (i < ret)
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			*line = ft_strjoin(*line, buf);
			return (1);
		}
		i++;
	}
	*line = ft_strjoin(*line, buf);
	if (ret == BUFFER_SIZE)
		return (0);
	else
		return (-1);
}

static void	cleanup_line(char **line)
{
	free(*line);
	*line = NULL;
}

static int	ft_get_next_line(int fd, char **line)
{
	static char	buf[FD_MAX][BUFFER_SIZE + 1];
	int			ret;

	*line = NULL;
	ret = ft_add_to_line(line, buf[fd]);
	while (ret != -1 && (*line)[ret] != '\n')
	{
		ret = read_into_buffer(fd, buf[fd]);
		if (ret < 1)
		{
			if (ret < 0)
			{
				cleanup_line(line);
			}
			return (ret);
		}
		buf[fd][ret] = '\0';
		ret = ft_add_to_line(line, buf[fd]);
	}
	if (ret == -1)
		cleanup_line(line);
	else
		(*line)[ret] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int	result;

	if (fd < 0 || fd > FD_MAX || !line || BUFFER_SIZE < 1)
		return (-1);
	result = ft_get_next_line(fd, line);
	if (result == 0 || result == -1)
	{
		free(*line);
		*line = NULL;
	}	
	return (result);
}
