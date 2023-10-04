/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_geometry_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:30 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 17:15:46 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;

	determine_scale(pt_matrix);
	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].xf = pt_matrix->data[i][j].xf
				* pt_matrix->scale;
			pt_matrix->data[i][j].yf = pt_matrix->data[i][j].yf
				* pt_matrix->scale;
			pt_matrix->data[i][j].zf = pt_matrix->data[i][j].zf
				* pt_matrix->scale;
			j++;
		}
		i++;
	}
	update_px_coords(pt_matrix);
}

void	scale_2(t_meta *meta, float scale)
{
	unsigned int	i;
	unsigned int	j;
	t_ptmatrix		*pt_matrix;

	pt_matrix = &meta->pt_matrix;
	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].xf = pt_matrix->data[i][j].xf
				* scale;
			pt_matrix->data[i][j].yf = pt_matrix->data[i][j].yf
				* scale;
			pt_matrix->data[i][j].zf = pt_matrix->data[i][j].zf
				* scale;
			j++;
		}
		i++;
	}
}

void	zoom(t_meta *meta, float scale)
{
	center_to_og(&meta->pt_matrix);
	scale_2(meta, scale);
	update_int_coords(&meta->pt_matrix);
	og_to_center(&meta->pt_matrix);
	meta->re_render = 1;
}

void	center_to_im(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].xf = pt_matrix->data[i][j].x
				+ IMG_WIDTH / 2.0;
			pt_matrix->data[i][j].yf = pt_matrix->data[i][j].y
				+ IMG_HEIGHT / 2.0;
			j++;
		}
		i++;
	}
	update_px_coords(pt_matrix);
}

void	center_to_og(t_ptmatrix *points)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].x = points->data[i][j].x - points->x_c;
			points->data[i][j].xf = points->data[i][j].xf - points->x_c;
			points->data[i][j].y = points->data[i][j].y - points->y_c;
			points->data[i][j].yf = points->data[i][j].yf - points->y_c;
			points->data[i][j].z = points->data[i][j].z - points->z_c;
			points->data[i][j].zf = points->data[i][j].zf - points->z_c;
			j++;
		}
		i++;
	}
}
