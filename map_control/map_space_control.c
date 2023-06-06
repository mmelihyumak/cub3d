/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_space_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:04:57 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/05/31 18:39:42 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_space_control(char *map)
{
	int	i;
	int	mapsize;

	i = 0;
	mapsize = ft_strlen(map);
	while (i < mapsize && map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '1' || map[i] == '0')
			{
				while (map[i])
				{
					if (map[i] == '\n' && map[i + 1] == '\n')
						return (1);
					i++;
				}
			}
		}
		i++;
	}
	return (0);
}
