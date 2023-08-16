/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:17:05 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 22:00:40 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

void func(void)
{
	system("leaks fdf");
}

int	main(int argc, char *argv[])
{
	t_fdf	*env;
	atexit(func);

	if (argc == 2)
	{
		env = ft_init(argv[1]);
		env->map = ft_map_init();
		ft_check_valid(argv[1], env->map);
		env->camera = ft_camera_init(env);
		ft_hook_controls(env);
		ft_draw(env->map, env);
		mlx_loop(env->mlx);
	}
	else
		ft_return_error("Usage: ./fdf <filename>", 0);
}
