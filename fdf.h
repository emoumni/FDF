/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:16:56 by emoumni           #+#    #+#             */
/*   Updated: 2023/05/22 13:09:59 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h> 
# include "utils/utils.h"
# include "keys.h"
# include "struct.h"
# include <math.h> 

void		ft_check_valid(char *filename, t_map *map);
t_fdf		*ft_init(const char *path);
void		loop(t_point start, t_point end, float gradient, t_fdf *env);
t_camera	*ft_camera_init(t_fdf *env);
t_map		*ft_map_init(void);
int			ft_get_height(char *filename);
void		ft_get_z_min_max(t_map *map, int n);
int			ft_get_width(char *filename);
void		fill(int **n, char *line, int width);
int			ft_lerp(int first, int second, double p);
void		ft_2d_array_free(void **arr, size_t size);
void		ft_draw(t_map *map, t_fdf *env);
void		plot_pixel(t_fdf *env, int x, int y, int color);
void		line_draw(t_point s, t_point e, t_fdf *env);
t_point		project(int x, int y, t_fdf *env);
int			ft_min(int a, int b);
int			get_default_color(int z, t_map *map);
void		ft_return_error(const char *err_msg, int system_function);
double		ft_reset_angles(double angle);
float		ft_absolute(float n);
void		ft_hook_controls(t_fdf *env);
int			ft_ipart(float n);
float		ft_fpart(float n);
float		ft_rfpart(float n);
void		ft_swap(int *a, int *b);
int			ft_key_press(int keycode, void *params);
int			ft_mouse_down(int button, int x, int y, void *params);
int			ft_mouse_up(int button, int x, int y, void *params);
int			ft_mouse_move(int x, int y, void *params);
int			ft_close_win(void *params);

#endif
