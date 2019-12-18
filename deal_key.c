/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:26:52 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/16 23:36:42 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key(int key, t_map *map)
{
	if (key == 126)
		map->y_move = map->y_move - 10;
	if (key == 125)
		map->y_move = map->y_move + 10;
	if (key == 123)
		map->x_move = map->x_move - 10;
	if (key == 124)
		map->x_move = map->x_move + 10;
	if (key == 6)
		map->z_height = map->z_height + 2;
	if (key == 7)
		map->z_height = map->z_height - 2;
	else
		deal_key2(key, map);
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	print_menu(map);
	return (0);
}

int			deal_key2(int key, t_map *map)
{
	if (key == 8 || key == 9 || key == 10 || key == 11 || key == 12)
		map->color_change = 1;
	if (key == 34)
		map->iso_on = 1;
	if (key == 35)
		map->iso_on = 0;
	if (key == 53)
	{
		free_map(map);
		exit(0);
	}
	mlx_clear_window(map->mlx_ptr, map->win_ptr);
	draw(map);
	print_menu(map);
	return (0);
}
