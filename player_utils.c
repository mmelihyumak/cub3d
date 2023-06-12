/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:13:50 by melih             #+#    #+#             */
/*   Updated: 2023/06/12 21:14:56 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_pos_dir(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->pos_x = j;
				map->pos_y = i;
				map->direction = map->map[i][j];
			}
		}
	}
}

void	get_direction(t_map *map)
{
	if (map->direction == 'N')
	{
		map->dir_x = -1;
		map->fov_y = 0.90;
	}
	if (map->direction == 'W')
	{
		map->dir_y = -1;
		map->fov_x = -0.90;
	}
	if (map->direction == 'S')
	{
		map->dir_x = 1;
		map->fov_y = -0.90;
	}
	if (map->direction == 'E')
	{
		map->dir_y = 1;
		map->fov_x = 0.90;
	}
}
