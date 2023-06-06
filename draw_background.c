/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:35:49 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/06 22:32:58 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_map *map)
{
	int	x;
	int	y;

	y = map->y_resolution / 2;
	while (y < map->y_resolution)
	{
		x = 0;
		while (x < map->x_resolution)
		{
			mlx_pixel_put(map->mlx_ptr, map->mlx_win, x, y, 0xDC6419);
			mlx_pixel_put(map->mlx_ptr, map->mlx_win, x, y - (map->y_resolution / 2), 0xE11E00);
			x++;
		}
		y++;
	}
}

void	draw_background(t_map *map)
{
	map->floor_path = ft_strdup("./textures/wood.xpm");
	map->sky_path = ft_strdup("./textures/blue.xpm");
	map->img_floor = mlx_xpm_file_to_image(map->mlx_ptr, map->floor_path, &map->width, &map->height);
	map->img_sky = mlx_xpm_file_to_image(map->mlx_ptr, map->sky_path, &map->width, &map->height);
	draw_floor(map);
}
