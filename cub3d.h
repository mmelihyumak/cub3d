/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:57 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/08 01:16:52 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_line/get_next_line.h"
# include "libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*floor_path;
	char	*sky_path;
	void	*img_floor;
	void	*img_sky;
	char	*img_addr;
	char	**fullmap;
	char	*so;
	char	*no;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**map;
	int		width;
	int		height;
	float	x_resolution;
	float	y_resolution;
}			t_map;

int				map_space_control(char *map);
int				check_map_name(char *str);
int				map_control(char *map, int type, t_map *mapes);
int				map_size(char **map);
void			free_map(char **map);
char			*get_map(char *map);
void			map_error(int type);
void			fill_map(t_map *mapes);
void			map_height_weidth(t_map *mapes);
int				map_param_check(char **fillmap);
int				not_value_check(char *str, char *type);
void			full_map_space_trim(t_map *mapes);
int				rgb_check(t_map *mapes);
unsigned int	hex_to_decimal(const char *hex);


int			key_p(t_map *map);
int			key_press(int key, t_map *map);
void		draw_background(t_map *map);
void		draw_cubes(t_map *map);
void		get_image_data(t_map *map);
void		move_forward(t_map *map);

#endif