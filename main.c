/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:24 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/12 15:43:03 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_map(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (1);
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	map_control(char *map, int type, t_map *mapes)
{
	if (empty_map(map) && type == 1)
		return (1);
	if (map_space_control(map) && type == 1)
		return (1);
	else if (type == 2)
	{
		if (map_param_check(mapes->fullmap))
			return (1);
	}
	return (0);
}

int	file_check(t_map *mapes)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = open(mapes->no, O_RDONLY);
	b = open(mapes->so, O_RDONLY);
	c = open(mapes->we, O_RDONLY);
	d = open(mapes->ea, O_RDONLY);
	if (a < 0 || b < 0 || c < 0 || d < 0)
		return (1);
	return (0);
}

unsigned int	hex_to_decimal(const char *hex)
{
	unsigned int	decimal;
	char			c;
		int value;

	decimal = 0;
	// Hexadecimal sayıyı dönüştürme
	for (int i = 2; hex[i] != '\0'; i++)
	{
		c = hex[i];
		if (c >= '0' && c <= '9')
		{
			value = c - '0';
		}
		else if (c >= 'A' && c <= 'F')
		{
			value = c - 'A' + 10;
		}
		else if (c >= 'a' && c <= 'f')
		{
			value = c - 'a' + 10;
		}
		else
		{
			printf("Geçersiz hex renk kodu: %s\n", hex);
			exit(1);
		}
		decimal = decimal * 16 + value;
	}
	return (decimal);
}

void	start_mlx(t_map *map)
{
	get_pos_dir(map);
	get_direction(map);
	map->move_speed = 0.1;
	map->rotate_speed = 0.04;
	map->img_width = 64;
	map->img_height = 64;
	map->x_resolution = 1280;
	map->y_resolution = 640;
	map->mlx_ptr = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->x_resolution,
			map->y_resolution, "Cub3d");
	get_image_data(map);
	map->img_screen = mlx_new_image(map->mlx_ptr, map->x_resolution, map->y_resolution);
	map->screen_data = (int *)mlx_get_data_addr(map->img_screen, &map->bpp, &map->size_line, &map->endian);
	mlx_loop_hook(map->mlx_ptr, &raycasting, map);
	mlx_hook(map->mlx_win, 2, 0, &key_press, map);
	mlx_hook(map->mlx_win, 17, 0, &key_p, map);
	mlx_loop(map->mlx_ptr);
}

char	*convertToHex(int red, int green, int blue, char *hexCode)
{
	char	*hexValues;

	hexValues = ft_strdup("0123456789ABCDEF");
	hexCode[0] = '0';
	hexCode[1] = 'x';
	hexCode[2] = hexValues[(red >> 4) & 0x0F];
	hexCode[3] = hexValues[red & 0x0F];
	hexCode[4] = hexValues[(green >> 4) & 0x0F];
	hexCode[5] = hexValues[green & 0x0F];
	hexCode[6] = hexValues[(blue >> 4) & 0x0F];
	hexCode[7] = hexValues[blue & 0x0F];
	hexCode[8] = '\0';
	free(hexValues);
	return (hexCode);
}

void	rgb_to_hex(t_map *mapes)
{
	char	**rgb;

	rgb = ft_split(mapes->f, ',');
	mapes->f = convertToHex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]),
			mapes->f);
	free_map(rgb);
	rgb = ft_split(mapes->c, ',');
	mapes->c = convertToHex(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]),
			mapes->c);
	free_map(rgb);
}

int	main(int argc, char **argv)
{
	char	*map_line;
	t_map	mapes;
	int		i;

	if (argc != 2)
		return (0);
	if (check_map_name(argv[1]))
		map_error(1);
	map_line = get_map(argv[1]);
	if (map_control(map_line, 1, &mapes))
		map_error(2);
	mapes.fullmap = ft_split(map_line, '\n');
	full_map_space_trim(&mapes);
	if (map_control(map_line, 2, &mapes))
		map_error(2);
	mapes.map = malloc(sizeof(char *) * (map_size(mapes.fullmap) + 1));
	fill_map(&mapes);
	if (rgb_check(&mapes) || file_check(&mapes))
		map_error(2);
	rgb_to_hex(&mapes);
	map_height_weidth(&mapes);
	i = 0;
	printf("f: %s\n", mapes.f);
	printf("c: %s\n", mapes.c);
	printf("s: %s\n", mapes.so);
	printf("n: %s\n", mapes.no);
	printf("w: %s\n", mapes.we);
	printf("e: %s\n", mapes.ea);
	printf("%d\n", ft_atoi("0x0000FF"));
	while (mapes.map[i])
	{
		printf("%s\n", mapes.map[i]);
		i++;
	}
	start_mlx(&mapes);
	free(map_line);
	free_map(mapes.fullmap);
	free_map(mapes.map);
	system("leaks cub3d");
	return (0);
}
