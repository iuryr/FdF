/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_load_points_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:18:14 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:02:47 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_minmax(t_ptmatrix *points)
{
	points->x_max = 0;
	points->x_min = 0;
	points->y_max = 0;
	points->y_min = 0;
}

void	set_float_coords(t_ptmatrix *points)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].xf = floor(points->data[i][j].x);
			points->data[i][j].yf = floor(points->data[i][j].y);
			points->data[i][j].zf = floor(points->data[i][j].z);
			j++;
		}
		i++;
	}
}

void	update_minmax(t_ptmatrix *points)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			if (points->data[i][j].x < points->x_min)
				points->x_min = points->data[i][j].x;
			if (points->data[i][j].x > points->x_max)
				points->x_max = points->data[i][j].x;
			if (points->data[i][j].y < points->y_min)
				points->y_min = points->data[i][j].y;
			if (points->data[i][j].y > points->y_max)
				points->y_max = points->data[i][j].y;
			j++;
		}
		i++;
	}
}

void	update_center(t_ptmatrix *points)
{
	points->x_c = (points->x_max - points->x_min) / 2;
	points->y_c = (points->y_max - points->y_min) / 2;
}

void	update_int_coords(t_ptmatrix *points)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].x = (int) roundf(points->data[i][j].xf);
			points->data[i][j].y = (int) roundf(points->data[i][j].yf);
			points->data[i][j].z = (int) roundf(points->data[i][j].zf);
			j++;
		}
		i++;
	}
}
