/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:23:23 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/16 23:26:14 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_params(t_map *map)
{
	zoom(map);
	if (!map->color_change)
		color(map);
	else
		color_change(map);
	if (map->iso_on == 1)
		isometric(map);
	move(map);
}

void		bresenham(t_map map)
{
	float	x_step;
	float	y_step;
	int		max;

	map.z = map.z_map[(int)map.y][(int)map.x];
	map.z1 = map.z_map[(int)map.y1][(int)map.x1];
	set_params(&map);
	x_step = map.x1 - map.x;
	y_step = map.y1 - map.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(map.x - map.x1) || (int)(map.y - map.y1))
	{
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, map.x, map.y, map.color);
		map.x += x_step;
		map.y += y_step;
	}
}

void		draw(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			if (map->x < map->width - 1)
			{
				map->x1 = map->x + 1;
				map->y1 = map->y;
				bresenham(*map);
			}
			if (map->y < map->height - 1)
			{
				map->x1 = map->x;
				map->y1 = map->y + 1;
				bresenham(*map);
			}
			map->x++;
		}
		map->y++;
	}
}
