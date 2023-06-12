/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:57 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/12 15:32:33 by melih            ###   ########.fr       */
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
	void	*img_blue;
	void	*img_grey;
	void	*img_red;
	void	*img_purple;
	void	*img_screen;
	int		*blue_data;
	int		*grey_data;
	int		*red_data;
	int		*purple_data;
	int		*screen_data;
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

	int		bpp;
	int		size_line;
	int		endian;


	
	int			img_width;
	int			img_height;
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		raydir_x;
	double		raydir_y;
	double		plane_x;
	double		plane_y;
	double		fov_x;
	double		fov_y;
	double		camera_x;
	double		camera_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		time;
	double		oldtime;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		wall_x;
	double		step;
	double		tex_pos;
	double		move_speed;
	double		rotate_speed;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			next_pos;
	int			tex_x;
	int			tex_y;
	int			color;
	char		direction;
	int			x_resolution;
	int			y_resolution;
}				t_map;

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
void		move_back(t_map *map);
void		move_right(t_map *map);
void		move_left(t_map *map);
void		rotate_left(t_map *map);
void		rotate_right(t_map *map);
void		get_pos_dir(t_map *map);
int			raycasting(t_map *map);
void		get_direction(t_map *map);

#endif