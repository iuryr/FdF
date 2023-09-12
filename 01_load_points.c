/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_load_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:38 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/30 16:05:36 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_pt_matrix(t_meta *meta)
{
	pt_matrix_init(meta);
	alloc_ptmatrix_data(&meta->pt_matrix);
	load_points(meta);
}

void	pt_matrix_init(t_meta *meta)
{
	meta->pt_matrix.rows = meta->map.rows;
	meta->pt_matrix.cols = meta->map.cols;
}

void	alloc_ptmatrix_data(t_ptmatrix *pt_matrix)
{
	unsigned int	i;

	pt_matrix->data = (t_point **) malloc(pt_matrix->rows * sizeof(t_point *));
	i = 0;
	while (i < pt_matrix->rows)
	{
		pt_matrix->data[i] = malloc(pt_matrix->cols * sizeof(t_point));
		i++;
	}
}

int	determine_scale(t_map map)
{
	int	scale_x;
	int	scale_y;

	scale_x = WINDOW_WIDTH / map.cols;
	scale_y = WINDOW_HEIGHT / map.rows;
	if (scale_x <= scale_y)
		return (scale_x);
	else
		return (scale_y);
}

void	set_minmax(t_ptmatrix *points)
{
	points->x_max = 0;
	points->x_min = 0;
	points->y_max = 0;
	points->y_min = 0;
}

void	update_minmax(t_ptmatrix *points)
{
	unsigned int i;
	unsigned int j;

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

void	set_float_coords(t_ptmatrix *points)
{
	unsigned int i;
	unsigned int j;

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

void	load_points(t_meta *meta)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].x = i * determine_scale(meta->map);
			meta->pt_matrix.data[i][j].y = j * determine_scale(meta->map);
			meta->pt_matrix.data[i][j].z = meta->map.data[i][j];
			j++;
		}
		i++;
	}
	set_minmax(&meta->pt_matrix);
	update_minmax(&meta->pt_matrix);
	update_center(&meta->pt_matrix);
	set_float_coords(&meta->pt_matrix);
}
