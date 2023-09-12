/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:30 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/30 15:49:53 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_meta *meta, int scale)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].x = i * scale;
			meta->pt_matrix.data[i][j].y = j * scale;
			meta->pt_matrix.data[i][j].z = meta->map.data[i][j] * scale;
			j++;
		}
		i++;
	}
}

void	rotation_45dl(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;
	float				x;
	float				y;
	double			theta;

	theta = M_PI / 6;
	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			x = (pt_matrix->data[i][j].x - pt_matrix->x_c) * cos(theta)
				- (pt_matrix->data[i][j].y - pt_matrix->y_c) * sin(theta);
			y = (pt_matrix->data[i][j].x - pt_matrix->x_c) * sin(theta)
				+ (pt_matrix->data[i][j].y - pt_matrix->y_c) * cos(theta);
			pt_matrix->data[i][j].xf = x + pt_matrix->x_c;
			pt_matrix->data[i][j].yf = y + pt_matrix->y_c;
			j++;
		}
		i++;
	}
}

//rotate figure through xy theta radians clockwise around its own center
void	rot_xy_ac(t_ptmatrix *points, float theta)
{
	unsigned int i;
	unsigned int j;
	double x;
	double y;
	double xt;
	double yt;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			xt = points->data[i][j].xf - points->x_c;
			yt = points->data[i][j].yf - points->y_c;

			x = (xt * cos(theta))  - (yt * sin(theta));
			y = (xt * sin(theta))  + (yt * cos(theta));

			points->data[i][j].xf = x + points->x_c;
			points->data[i][j].yf = y + points->y_c;
			j++;
		}
		i++;
	}
}
