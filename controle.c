/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:11:03 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/21 21:20:17 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_win(void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	mlx_destroy_image(env->mlx, env->img);
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

void	ft_hook_controls(t_fdf *env)
{
	mlx_hook(env->win, 2, 0, ft_key_press, env);
	mlx_hook(env->win, 4, 0, ft_mouse_down, env);
	mlx_hook(env->win, 5, 0, ft_mouse_up, env);
	mlx_hook(env->win, 6, 0, ft_mouse_move, env);
	mlx_hook(env->win, 17, 0, ft_close_win, env);
}

double	ft_reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
