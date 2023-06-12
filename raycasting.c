/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:12:29 by melih             #+#    #+#             */
/*   Updated: 2023/06/12 21:53:14 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_map *map)
{
	int	x;
	int	a;

	x = 0;
	draw_background(map);
	while (x < map->x_resolution)
	{
		map->camera_x = 2 * x / (double)map->x_resolution - 1;
		map->raydir_x = map->dir_x + map->fov_x * map->camera_x;
		map->raydir_y = map->dir_y + map->fov_y * map->camera_x;
		map->map_x = (int)map->pos_x;
		map->map_y = (int)map->pos_y;
		map->delta_dist_x = fabs(1 / map->raydir_x);
		map->delta_dist_y = fabs(1 / map->raydir_y);
		map->hit = 0;
		if (map->raydir_x < 0)
		{
			map->step_x = -1;
			map->side_dist_x = (map->pos_x - map->map_x) * map->delta_dist_x;
		}
		else
		{
			map->step_x = 1;
			map->side_dist_x = (map->map_x + 1.0 - map->pos_x) * map->delta_dist_x;
		}
		if (map->raydir_y < 0)
		{
			map->step_y = -1;
			map->side_dist_y = (map->pos_y - map->map_y) * map->delta_dist_y;
		}
		else
		{
			map->step_y = 1;
			map->side_dist_y = (map->map_y + 1.0 - map->pos_y) * map->delta_dist_y;
		}
		while (map->hit == 0)
		{
			if (map->side_dist_x < map->side_dist_y)
			{
				map->side_dist_x += map->delta_dist_x;
				map->map_x += map->step_x;
				map->side = 0;
			}
			else
			{
				map->side_dist_y += map->delta_dist_y;
				map->map_y += map->step_y;
				map->side = 1;
			}
			if (map->map_x < 0 || map->map_y < 0)
			{
				if (map->map_x < 0)
					map->map_x = 0;
				if (map->map_y < 0)
					map->map_y = 0;
			}
			if (map->map[map->map_x][map->map_y] != '0')
				map->hit = 1;
		}
		if (map->side == 0)
			map->perp_wall_dist = (map->map_x - map->pos_x + (1 - map->step_x) / 2) / map->raydir_x;
		else
			map->perp_wall_dist = (map->map_y - map->pos_y + (1 - map->step_y) / 2) / map->raydir_y;
		map->line_height = (int)(map->y_resolution / map->perp_wall_dist);
		map->draw_start = -map->line_height / 2 + map->y_resolution / 2;
		if (map->draw_start < 0)
			map->draw_start = 0;
		map->draw_end = map->line_height / 2 + map->y_resolution / 2;
		if (map->draw_end >= map->y_resolution)
			map->draw_end = map->y_resolution - 1;
		map->next_pos = map->map[map->map_x][map->map_y] - 1;
		if (map->side == 0)
			map->wall_x = map->pos_y + map->perp_wall_dist * map->raydir_y;
		else
			map->wall_x = map->pos_x + map->perp_wall_dist * map->raydir_x;
		map->wall_x -= floor(map->wall_x);
		map->tex_x = (int)(map->wall_x * (double)map->img_width);
		if (map->side == 0 && map->raydir_x > 0)
			map->tex_x = map->img_width - map->tex_x - 1;
		if (map->side == 1 && map->raydir_y < 0)
			map->tex_x =  map->img_width - map->tex_x - 1;
		map->step = 1.0 * map->img_height / map->line_height;
		map->tex_pos = (map->draw_start - map->y_resolution / 2 + map->line_height / 2) * map->step;
		a = map->draw_start;
		while (a < map->draw_end)
		{
			map->tex_y = (int)map->tex_pos & (map->img_height - 1);
			map->tex_pos += map->step;
			if (map->raydir_x > 0 && map->side != 1)
				map->color = map->red_data \
				[map->img_height * map->tex_y + map->tex_x];
			else if (map->raydir_x < 0 && map->side != 1)
				map->color = map->blue_data \
				[map->img_height * map->tex_y + map->tex_x];
			else if ((map->raydir_x < 2 && map->raydir_y > 0) \
			&& map->side == 1)
				map->color = map->grey_data \
				[map->img_height * map->tex_y + map->tex_x];
			else
				map->color = map->purple_data \
				[map->img_height * map->tex_y + map->tex_x];
			map->screen_data[a * map->x_resolution + x] = map->color;
			a++;
		}
		x++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img_screen, 0, 0);
	return (0);
}