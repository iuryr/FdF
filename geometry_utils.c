/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:13:33 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/18 18:27:46 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	determine_scale(t_ptmatrix *points)
{
	float	scale_x;
	float	scale_y;

	determine_range(points);
	scale_x = WINDOW_WIDTH / (float) points->x_range;
	scale_y = WINDOW_HEIGHT / (float) points->y_range;
	if (scale_x <= scale_y)
		points->scale = scale_x * 0.9;
	else
		points->scale = scale_y * 0.9;
}

void	determine_range(t_ptmatrix *points)
{
	points->x_range = points->x_max - points->x_min;
	points->y_range = points->y_max - points->y_min;
}

void	prepare_render(t_ptmatrix *points)
{
	unsigned int i;
	unsigned int j;

	update_px_coords(points);
	determine_scale(points);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].x = (points->data[i][j].x - points->x_min)
				* points->scale + points->x_offset;
			points->data[i][j].y = (points->data[i][j].y - points->y_min)
				* points->scale + points->y_offset;
			j++;
		}
		i++;
	}
}
