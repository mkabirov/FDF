/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:37:30 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/17 01:02:04 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*map_create(void)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->fd = 0;
	map->line_num = 1;
	map->x_move = 250;
	map->y_move = 250;
	map->z_height = 1;
	map->iso_on = 0;
	map->color_change = 0;
	map->win_w = 800;
	map->win_h = 750;
	map->zoom = 25;
	return (map);
}

int			free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->z_map[i]);
		i++;
	}
	free(map->z_map);
	return (0);
}
