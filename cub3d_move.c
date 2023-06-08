/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:41:57 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/08 01:17:17 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map)
{
	float	x;
	float	y;
	static float	slide_y;
	static float	slide_x;

	slide_y += 1;
	slide_x += 1;
	y = map->y_resolution / 2 - 32 - slide_y;
	while (y <= map->y_resolution / 2 + 32 + slide_y)
	{
		if (x < map->x_resolution / 2 - 32 || x > map->x_resolution / 2 + 32)
		{
			x = map->x_resolution / 2 - 32 - slide_x;
			while (x <= map->x_resolution / 2 + 32 + slide_x)
			{
				mlx_pixel_put(map->mlx_ptr, map->mlx_win, x, y, 0xF70202);
				x += 1;
			}
		}
		y += 1;
	}
}

void	move_back(void)
{
	
}
