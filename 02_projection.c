/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:08 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/22 15:22:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(t_map *map, t_point *proj_point_array)
{
	unsigned int	index;
	unsigned int	i;
	unsigned int	j;

	index = 0;
	i = 0;
	while (index < map->points_count)
	{
		while(i < map->rows)
		{
			j = 0;
			while (j < map->cols)
			{
				proj_point_array[index].x = 1 / sqrt(2) * (i - map->data[i][j]);
				proj_point_array[index].y =  i - 2*j + map->data[i][j];
				index++;
				j++;
			}
			i++;
		}
	}
}
