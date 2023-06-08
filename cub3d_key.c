/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:12:14 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/08 00:27:30 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_p(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}

int	key_press(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->mlx_win);
		exit(0);
	}
	if (key == 13)
		move_forward(map);
	return (0);
}
