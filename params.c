/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:21:14 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/17 00:28:51 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(t_map *map)
{
	map->x = map->zoom * map->x;
	map->y = map->zoom * map->y;
	map->x1 = map->zoom * map->x1;
	map->y1 = map->zoom * map->y1;
}

void		move(t_map *map)
{
	map->x = map->x_move + map->x;
	map->y = map->y_move + map->y;
	map->x1 = map->x_move + map->x1;
	map->y1 = map->y_move + map->y1;
}

void		isometric(t_map *map)
{
	map->x = (map->x - map->y) * cos(0.8);
	map->y = (map->x + map->y) * sin(0.8) - map->z * map->z_height;
	map->x1 = (map->x1 - map->y1) * cos(0.8);
	map->y1 = (map->x1 + map->y1) * sin(0.8) - map->z1 * map->z_height;
}

void		color(t_map *map)
{
	if (map->z)
		map->color = GREEN;
	else
		map->color = L_GREEN;
}

void		color_change(t_map *map)
{
	{
		if (map->z)
			map->color = L_ORANGE;
		else
			map->color = ORANGE;
	}
}
