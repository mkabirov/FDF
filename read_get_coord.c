/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_getz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 16:57:46 by mkabirov          #+#    #+#             */
/*   Updated: 2019/11/16 23:16:29 by mkabirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			count_xy(char *file, t_map *map)
{
	char		*line;
	int			i;
	int			width;

	map->fd = open(file, O_RDONLY);
	while ((get_next_line(map->fd, &line)) == 1)
	{
		i = 0;
		width = 0;
		while (line[i])
		{
			if (line[i] == ' ')
				i++;
			else if (line[i] == '\n')
				break ;
			else
			{
				while (line[i] != '\0' && line[i] != ' ')
					i++;
				width++;
			}
		}
		check_width(map, width, line);
	}
	close(map->fd);
}

void			check_width(t_map *map, int width, char *line)
{
	static int	first_line = 1;

	if (first_line)
	{
		map->width = width;
		first_line = 0;
	}
	else if (width != map->width)
		error_mes("error: map is invalid");
	map->height++;
	free(line);
}

void			fill_array(int *z_line, char *line)
{
	char		**z_val;
	int			i;

	z_val = ft_strsplit(line, ' ');
	i = 0;
	while (z_val[i])
	{
		z_line[i] = ft_atoi(z_val[i]);
		free(z_val[i]);
		i++;
	}
	free(z_val);
}

void			allocate_array(char *file, t_map *map)
{
	int			i;
	char		*line;

	map->z_map = (int **)malloc(sizeof(int*) * (map->height));
	i = 0;
	while (i < map->height)
		map->z_map[i++] = (int *)malloc(sizeof(int*) * (map->width));
	map->fd = open(file, O_RDONLY);
	i = 0;
	while ((get_next_line(map->fd, &line) > 0))
	{
		fill_array(map->z_map[i], line);
		free(line);
		i++;
	}
	close(map->fd);
	map->z_map[i] = NULL;
}
