/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:44:52 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/17 01:11:24 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MAX(a, b) (a > b ? a : b)
# define MOD(n) (n < 0 ? -n : n)
# define GREEN 0x69b543
# define L_GREEN 0x396e1f
# define ORANGE 0xa733d05
# define L_ORANGE 0xe07d16

# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_map
{
	int			fd;
	int			height;
	int			width;
	int			line_num;
	int			**z_map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			zoom;
	int			color;
	int			color_change;
	int			x_move;
	int			y_move;
	int			z;
	int			z1;
	int			z_height;
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			iso_on;
	int			win_w;
	int			win_h;
}				t_map;

t_map			*map_create(void);
void			count_xy(char *file, t_map *map);
void			check_width(t_map *map, int width, char *line);
int				deal_key(int key, t_map *map);
void			allocate_array(char *file, t_map *map);
void			fill_array(int *z_line, char *line);
void			window_size(t_map *map);
void			bresenham(t_map map);
void			draw(t_map *map);
void			isometric(t_map *map);
void			color(t_map *map);
void			color_change(t_map *map);
void			zoom(t_map *map);
void			move(t_map *map);
void			print_menu(t_map *map);
void			set_params(t_map *map);
int				deal_key2(int key, t_map *map);
void			error_mes(char *s);
int				free_map(t_map *map);

#endif
