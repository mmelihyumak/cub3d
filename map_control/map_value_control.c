/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozdemi <rbozdemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:37:16 by rbozdemi          #+#    #+#             */
/*   Updated: 2023/06/06 16:20:49 by rbozdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	not_value_check(char *str, char *type)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, type, ft_strlen(type)))
		return (1);
	if (ft_strlen(type) == 1)
		return (0); // fonksiyon gelicek
	str += ft_strlen(type);
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == '/')
			return (0);
		if (str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (1);
}

int	map_param_check(char **fillmap)
{
	int	i;
	int	j;
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;

	i = 6;
	no = 0;
	so = 0;
	we = 0;
	ea = 0;
	f = 0;
	c = 0;
	j = 0;
	while (i && fillmap[j])
	{
		if (!not_value_check(fillmap[j], "NO"))
			no++;
		else if (!not_value_check(fillmap[j], "SO"))
			so++;
		else if (!not_value_check(fillmap[j], "WE"))
			we++;
		else if (!not_value_check(fillmap[j], "EA"))
			ea++;
		else if (!not_value_check(fillmap[j], "F"))
			f++;
		else if (!not_value_check(fillmap[j], "C"))
			c++;
		i--;
		j++;
	}
	if (no > 1 || so > 1 || we > 1 || ea > 1 || f > 1 || c > 1)
		return (1);
	if (no == 0 || so == 0 || we == 0 || ea == 0 || f == 0 || c == 0)
		return (1);
	if (fillmap[j] == NULL || (fillmap[j][0] != '1' && fillmap[j][0] != ' '
			&& fillmap[j][0] != '\t' && fillmap[j][0] != '0'))
		return (1);
	return (0);
}
