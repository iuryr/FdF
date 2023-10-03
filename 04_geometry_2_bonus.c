/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_geometry_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:13:33 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:03:22 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	determine_scale(t_ptmatrix *points)
{
	float	scale_x;
	float	scale_y;

	determine_range(points);
	scale_x = IMG_WIDTH / (float) points->x_range;
	scale_y = IMG_HEIGHT / (float) points->y_range;
	if (scale_x <= scale_y)
		points->scale = scale_x * 0.9;
	else
		points->scale = scale_y * 0.9;
}

//rotate figure through xy theta radians clockwise around its own center
void	rot_az_ac(t_ptmatrix *points, float theta)
{
	t_trig			trig;
	unsigned int	i;
	unsigned int	j;
	float			xt;
	float			yt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			xt = points->data[i][j].xf;
			yt = points->data[i][j].yf;
			points->data[i][j].xf = xt * trig.cosa
				- yt * trig.sina;
			points->data[i][j].yf = xt * trig.sina
				+ yt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
}

//rotate figure through xz theta radians clockwise around its own center
void	rot_ay_ac(t_ptmatrix *points, float theta)
{
	t_trig			trig;
	unsigned int	i;
	unsigned int	j;
	float			xt;
	float			zt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			xt = points->data[i][j].xf;
			zt = points->data[i][j].zf;
			points->data[i][j].xf = xt * trig.cosa
				+ zt * trig.sina;
			points->data[i][j].zf = -xt * trig.sina
				+ zt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
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
	meta->re_render = 1;
}

void	apply_neg_offset_y(t_meta *meta)
{
	unsigned int i;
	unsigned int j;

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

void	apply_pos_offset_y(t_meta *meta)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].yf += 10;
			j++;
		}
		i++;
	}
	update_px_coords(&meta->pt_matrix);
	meta->re_render = 1;
}

void	apply_neg_offset_x(t_meta *meta)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].xf -= 10;
			j++;
		}
		i++;
	}
	update_px_coords(&meta->pt_matrix);
	meta->re_render = 1;
}

void	apply_pos_offset_x(t_meta *meta)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].xf += 10;
			j++;
		}
		i++;
	}
	update_px_coords(&meta->pt_matrix);
	meta->re_render = 1;
}
