/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_geometry_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:10:31 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 17:15:06 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
			points->data[i][j].z = points->data[i][j].z + points->z_c;
			points->data[i][j].zf = points->data[i][j].zf + points->z_c;
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

//rotate figure through yz theta radians clockwise around its own center
void	rot_ax_ac(t_ptmatrix *points, float theta)
{
	t_trig			trig;
	unsigned int	i;
	unsigned int	j;
	float			yt;
	float			zt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			yt = points->data[i][j].yf;
			zt = points->data[i][j].zf;
			points->data[i][j].yf = yt * trig.cosa
				- zt * trig.sina;
			points->data[i][j].zf = yt * trig.sina
				+ zt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
}

void	rot_ax(t_meta *meta, float theta)
{
	center_to_og(&meta->pt_matrix);
	rot_ax_ac(&meta->pt_matrix, theta);
	update_int_coords(&meta->pt_matrix);
	og_to_center(&meta->pt_matrix);
	meta->pt_matrix.theta_x += theta;
	meta->re_render = 1;
}

void	apply_neg_offset_y(t_meta *meta)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].yf -= 10;
			j++;
		}
		i++;
	}
	update_px_coords(&meta->pt_matrix);
	meta->re_render = 1;
}
