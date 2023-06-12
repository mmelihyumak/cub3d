/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:29:14 by melih             #+#    #+#             */
/*   Updated: 2023/06/12 14:57:39 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_image_data(t_map *map)
{
	int	bpp;
	int	size_line;
	int	endian;
	
	bpp = 0;
	size_line = 0;
	endian = 0;
	map->img_blue = mlx_xpm_file_to_image(map->mlx_ptr, map->no, &map->width, &map->height);
	map->img_grey = mlx_xpm_file_to_image(map->mlx_ptr, map->so, &map->width, &map->height);
	map->img_red = mlx_xpm_file_to_image(map->mlx_ptr, map->we, &map->width, &map->height);
	map->img_purple = mlx_xpm_file_to_image(map->mlx_ptr, map->ea, &map->width, &map->height);
	map->blue_data = (int *)mlx_get_data_addr(map->img_blue, &bpp, &size_line, &endian);
	map->grey_data = (int *)mlx_get_data_addr(map->img_grey, &bpp, &size_line, &endian);
	map->red_data = (int *)mlx_get_data_addr(map->img_red, &bpp, &size_line, &endian);
	map->purple_data = (int *)mlx_get_data_addr(map->img_purple, &bpp, &size_line, &endian);
}