/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_geometry_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:30 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:33:35 by iusantos         ###   ########.fr       */
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

void	center_to_wm(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].x = pt_matrix->data[i][j].x
				+ WINDOW_WIDTH / 2;
			pt_matrix->data[i][j].y = pt_matrix->data[i][j].y
				+ WINDOW_HEIGHT / 2;
			j++;
		}
		i++;
	}
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
			j++;
		}
		i++;
	}
}

void	og_to_center(t_ptmatrix *points)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].x = points->data[i][j].x + points->x_c;
			points->data[i][j].xf = points->data[i][j].xf + points->x_c;
			points->data[i][j].y = points->data[i][j].y + points->y_c;
			points->data[i][j].yf = points->data[i][j].yf + points->y_c;
			j++;
		}
		i++;
	}
}

void	init_trig(t_trig *angle, float theta)
{
	angle->cosa = cos(theta);
	angle->sina = sin(theta);
}
