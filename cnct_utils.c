/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cnct_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:09:51 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:09:29 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_color(int x, t_point s, t_point e, float factor)
{
	int		red;
	int		green;
	int		blue;
	float	percent;

	percent = ft_absolute(x - s.x) / ft_absolute(e.x - s.x);
	red = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
	green = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
	blue = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	red = (int)(red * factor);
	green = (int)(green * factor);
	blue = (int)(blue * factor);
	return ((red << 16) | (green << 8) | blue);
}

void	loop(t_point start, t_point end, float gradient, t_fdf *env)
{
	float	interpolated_y;
	int		x;

	interpolated_y = (float)start.y;
	x = start.x;
	while (x <= end.x)
	{
		if (env->steep)
		{
			plot_pixel(env, ft_ipart(interpolated_y), x,
				get_color(x, start, end, ft_rfpart(interpolated_y)));
			plot_pixel(env, ft_ipart(interpolated_y) + 1, x,
				get_color(x, start, end, ft_fpart(interpolated_y)));
		}
		else
		{
			plot_pixel(env, x, ft_ipart(interpolated_y),
				get_color(x, start, end, ft_rfpart(interpolated_y)));
			plot_pixel(env, x, ft_ipart(interpolated_y) + 1,
				get_color(x, start, end, ft_fpart(interpolated_y)));
		}
		interpolated_y += gradient;
		x++;
	}
}

void	line_draw(t_point s, t_point e, t_fdf *env)
{
	float	dy;
	float	dx;
	float	way;

	env->steep = ft_absolute(e.y - s.y) > ft_absolute(e.x - s.x);
	if (env->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	way = dy / dx;
	if (dx == 0.0f)
		way = 1.f;
	loop(s, e, way, env);
}
