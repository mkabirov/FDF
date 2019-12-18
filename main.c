/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:57:56 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/16 23:54:26 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_mes(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 0;
	if (argc == 2)
	{
		map = map_create();
		if ((map->fd = open(argv[1], O_RDONLY)) < 0)
			error_mes("error: file is not valid");
		count_xy(argv[1], map);
		allocate_array(argv[1], map);
		window_size(map);
		map->mlx_ptr = mlx_init();
		map->win_ptr = \
		mlx_new_window(map->mlx_ptr, map->win_w, map->win_h, "FDF");
		print_menu(map);
		draw(map);
		mlx_key_hook(map->win_ptr, deal_key, map);
		mlx_loop(map->mlx_ptr);
	}
	else
		error_mes("usage: ./fdf [filename]");
}
