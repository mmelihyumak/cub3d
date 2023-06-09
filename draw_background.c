/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:35:49 by muyumak           #+#    #+#             */
/*   Updated: 2023/06/12 01:33:38 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x_resolution)
	{
		y = 0;
		while (y < map->y_resolution / 2)
		{
			map->screen_data[y * map->x_resolution + x] = hex_to_decimal(map->c);
			y++;
		}
		x++;
	}
	x = 0;
	y = map->y_resolution / 2;
	while (x < map->x_resolution && y < map->y_resolution)
	{
		map->screen_data[y * map->x_resolution + x] = hex_to_decimal(map->f);
		x++;
		if (x == map->x_resolution)
		{
			y++;
			x = 0;
		}
	}
}

void	draw_cubes(t_map *map)
{
	int	x;
	int	y;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	
	bits_per_pixel = 0;
	size_line = 0;
	endian = 0;
	map->img_addr = mlx_get_data_addr(map->img_sky, &bits_per_pixel, &size_line, &endian);
	y = map->y_resolution / 2 - 32;
	while (y < map->y_resolution / 2 + 32)
	{
		x = map->x_resolution / 2 - 32;
		while (x < map->x_resolution / 2 + 32)
		{
			mlx_pixel_put(map->mlx_ptr, map->mlx_win, x, y, 0xF70202);
			x++;
		}
		y++;
	}
}

/*void	get_image_data(t_map *map)
{
	int	bits_per_pixel;
	int	size_line;
	int	x; 
	int	y;
	
	bits_per_pixel = 0;
	size_line = 0;
    for (y = 0; y < 64; y++) {
        for (x = 0; x < 64; x++) {
            // Pikselin adresini hesapla
            int pixel_index = y * size_line + (x * (bits_per_pixel / 8));
			printf("pixel_index: %d\n", pixel_index);
            unsigned char blue = map->img_addr[pixel_index];
            unsigned char green = map->img_addr[pixel_index + 1];
            unsigned char red = map->img_addr[pixel_index + 2];
            // Piksel değerlerini yazdır
            printf("Piksel (%d, %d): R=%u, G=%u, B=%u\n", x, y, red, green, blue);
        }
    }
}*/

void	draw_background(t_map *map)
{
	/*map->floor_path = ft_strdup("./textures/wood.xpm");
	map->sky_path = ft_strdup("./textures/blue.xpm");
	map->img_floor = mlx_xpm_file_to_image(map->mlx_ptr, map->floor_path, &width, &height);
	map->img_sky = mlx_xpm_file_to_image(map->mlx_ptr, map->sky_path, &map->width, &map->height);*/
	
	draw_floor(map);
	//mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->img_sky, 0, 0);
}
