/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:19:21 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:10:58 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_pixel(t_fdf *env, int x, int y, int color)
{
	int	pixel_offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel_offset = y * env->size_line + x * env->bpp / 8;
	env->data_addr[pixel_offset + 0] = color;
	env->data_addr[pixel_offset + 1] = color >> 8;
	env->data_addr[pixel_offset + 2] = color >> 16;
}

void	ft_get_z_min_max(t_map *map, int n)
{
	if (n > map->z_max)
		map->z_max = n;
	if (n < map->z_min)
		map->z_min = n;
}

void	ft_return_error(const char *err_msg, int system_function)
{
	if (!system_function)
	{
		write(STDERR_FILENO, err_msg, strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
	}
	else
		perror(err_msg);
	exit(EXIT_FAILURE);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_max - map->z_min;
	if (max == 0)
		return (0x0000FF);
	percent = ((double)(z - map->z_min) / max);
	if (percent < 0.2)
		return (0x0000FF);
	else if (percent < 0.4)
		return (0x3333FF);
	else if (percent < 0.6)
		return (0x6666FF);
	else if (percent < 0.8)
		return (0x9999FF);
	else
		return (0xCCCCFF);
}
