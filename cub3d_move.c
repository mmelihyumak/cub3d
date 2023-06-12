/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:41:57 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/12 16:15:07 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_map *map)
{
	if (map->map[(int)(map->pos_x + map->dir_x * map->move_speed)] \
	[(int)(map->pos_y)] == '0')
		map->pos_x += map->dir_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y + map->dir_y * map->move_speed)] != '1')
		map->pos_y += map->dir_y * map->move_speed;
}

void	move_back(t_map *map)
{
	if (map->map[(int)(map->pos_x - map->dir_x * map->move_speed)] \
	[(int)(map->pos_y)] == '0')
		map->pos_x -= map->dir_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y - map->dir_y * map->move_speed)] != '1')
		map->pos_y -= map->dir_y * map->move_speed;
}

void	move_left(t_map *map)
{
	if (map->map[(int)(map->pos_x - map->fov_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x -= map->fov_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y - map->fov_y * map->move_speed)] != '1')
		map->pos_y -= map->fov_y * map->move_speed;
}

void	move_right(t_map *map)
{
	if (map->map[(int)(map->pos_x + map->fov_x * map->move_speed)] \
	[(int)(map->pos_y)] != '1')
		map->pos_x += map->fov_x * map->move_speed;
	if (map->map[(int)(map->pos_x)] \
	[(int)(map->pos_y + map->fov_y * map->move_speed)] != '1')
		map->pos_y += map->fov_y * map->move_speed;
}

void	rotate_left(t_map *map)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(map->rotate_speed) \
	- map->dir_y * sin(map->rotate_speed);
	map->dir_y = old_dir_x * sin(map->rotate_speed) \
	+ map->dir_y * cos(map->rotate_speed);
	old_fov_x = map->fov_x;
	map->fov_x = map->fov_x * cos(map->rotate_speed) \
	- map->fov_y * sin(map->rotate_speed);
	map->fov_y = old_fov_x * sin(map->rotate_speed) \
	+ map->fov_y * cos(map->rotate_speed);
}

void	rotate_right(t_map *map)
{
	double	old_dir_x;
	double	old_fov_x;

	old_dir_x = map->dir_x;
	map->dir_x = map->dir_x * cos(-map->rotate_speed) \
	- map->dir_y * sin(-map->rotate_speed);
	map->dir_y = old_dir_x * sin(-map->rotate_speed) \
	+ map->dir_y * cos(-map->rotate_speed);
	old_fov_x = map->fov_x;
	map->fov_x = map->fov_x * cos(-map->rotate_speed) \
	- map->fov_y * sin(-map->rotate_speed);
	map->fov_y = old_fov_x * sin(-map->rotate_speed) \
	+ map->fov_y * cos(-map->rotate_speed);
}
