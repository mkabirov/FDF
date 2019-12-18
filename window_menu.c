/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:10:45 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/17 01:08:46 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		window_size(t_map *map)
{
	if (((map->height >= 25) && (map->height < 47)) ||
	((map->width >= 25) && (map->width < 47)))
	{
		map->x_move = 300;
		map->y_move = 200;
		map->win_w = 1000;
		map->win_h = 1000;
	}
	if (((map->height >= 47) && (map->height < 96)) ||
	((map->width >= 47) && (map->width < 96)))
	{
		map->x_move = 100;
		map->y_move = 200;
		map->win_w = 1000;
		map->win_h = 1200;
		map->zoom = 15;
	}
	if (map->height >= 96 || map->width >= 96)
	{
		map->x_move = 100;
		map->y_move = 200;
		map->win_w = 1000;
		map->win_h = 1300;
		map->zoom = 10;
	}
}

void		print_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->mlx_ptr;
	win = map->win_ptr;
	mlx_string_put(mlx, win, 15, y += 30, 0xc9c9c9, "Move: Arrows");
	mlx_string_put(mlx, win, 57, y += 25, 0xc9c9c9, "Isometric 3D: I Key");
	mlx_string_put(mlx, win, 57, y += 25, 0xc9c9c9, "Parallel: P Key");
	mlx_string_put(mlx, win, 57, y += 25, 0xc9c9c9, "Change Color: C Key");
	mlx_string_put(mlx, win, 57, y += 25, 0xc9c9c9, "Z-height: Z and X Key");
	mlx_string_put(mlx, win, 15, y += 25, 0xc9c9c9, "Exit: ESC");
}
