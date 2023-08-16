/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:15:52 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:09:44 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_lines(t_map *map, t_fdf *env, int x_moves, int y_moves)
{
	int	y;
	int	x;

	if (env->camera->x_angle > 0)
		y = map->height - 1;
	else
		y = 0;
	while (y >= 0 && y < map->height)
	{
		x = 0;
		if (env->camera->y_angle > 0)
			x = map->width - 1;
		while (x >= 0 && x < map->width)
		{
			if (x != map->width - 1)
				line_draw(project(x, y, env), project(x + 1, y, env), env);
			if (y != map->height - 1)
				line_draw(project(x, y, env), project(x, y + 1, env), env);
			x += x_moves;
		}
		y += y_moves;
	}
}

void	ft_draw(t_map *map, t_fdf *env)
{
	int	y_moves;
	int	x_moves;

	ft_bzero(env->data_addr, WIDTH * HEIGHT * (env->bpp / 8));
	y_moves = 1 - 2 * (env->camera->x_angle > 0);
	x_moves = 1 - 2 * (env->camera->y_angle > 0);
	ft_draw_lines(map, env, x_moves, y_moves);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
