/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:56 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 14:53:08 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_malloc_size(char **line, char *buf)
{
	char	*ret;
	int		line_len;
	int		buf_len;

	line_len = 0;
	while (*line && (*line)[line_len] && (*line)[line_len] != '\n')
		line_len++;
	buf_len = 0;
	while (buf[buf_len] && buf[buf_len] != '\n')
		buf_len++;
	ret = (char *)malloc(sizeof(char) * (buf_len + line_len + 1));
	if (!ret)
	{
		free(*line);
		return (NULL);
	}
	return (ret);
}

int	ft_add_to_line(char **line, char *buf)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_malloc_size(line, buf);
	if (!tmp)
		return (-1);
	i = 0;
	j = 0;
	while (*line && (*line)[i] && (*line)[i] != '\n')
		tmp[i++] = (*line)[j++];
	j = 0;
	while (buf[j] && buf[j] != '\n')
		tmp[i++] = buf[j++];
	tmp[i] = buf[j];
	free(*line);
	*line = tmp;
	i = 0;
	while (buf[j])
		buf[i++] = buf[++j];
	buf[i] = '\0';
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	return (i);
}
