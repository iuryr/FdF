/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:30 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/18 16:00:18 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_ptmatrix *pt_matrix, float scale)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].xf = pt_matrix->data[i][j].xf * scale;
			pt_matrix->data[i][j].yf = pt_matrix->data[i][j].yf * scale;
			pt_matrix->data[i][j].zf = pt_matrix->data[i][j].zf * scale;
			j++;
		}
		i++;
	}
	update_px_coords(pt_matrix);
}

void	center(t_ptmatrix *pt_matrix)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			pt_matrix->data[i][j].x = pt_matrix->data[i][j].x + WINDOW_WIDTH / 2 - pt_matrix->x_c ;
			pt_matrix->data[i][j].y = pt_matrix->data[i][j].y + WINDOW_HEIGHT / 2 - pt_matrix->y_c;
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

//rotate figure through xy theta radians clockwise around its own center
void	rot_az_ac(t_ptmatrix *points, float theta)
{
	t_trig		trig;
	unsigned int	i;
	unsigned int	j;
	float		xt;
	float		yt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			xt = points->data[i][j].xf;
			yt = points->data[i][j].yf;
			points->data[i][j].xf = xt * trig.cosa  - yt * trig.sina;
			points->data[i][j].yf = xt * trig.sina  + yt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
}

//rotate figure through xz theta radians clockwise around its own center
void	rot_ay_ac(t_ptmatrix *points, float theta)
{
	t_trig		trig;
	unsigned int	i;
	unsigned int	j;
	float		xt;
	float		zt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			xt = points->data[i][j].xf;
			zt = points->data[i][j].zf;
			points->data[i][j].xf = xt * trig.cosa  + zt * trig.sina;
			points->data[i][j].zf = -xt * trig.sina  + zt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
}

//rotate figure through yz theta radians clockwise around its own center
void	rot_ax_ac(t_ptmatrix *points, float theta)
{
	t_trig		trig;
	unsigned int	i;
	unsigned int	j;
	float		yt;
	float		zt;

	init_trig(&trig, theta);
	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			yt = points->data[i][j].yf;
			zt = points->data[i][j].zf;
			points->data[i][j].yf = yt * trig.cosa  - zt * trig.sina;
			points->data[i][j].zf = yt * trig.sina  + zt * trig.cosa;
			j++;
		}
		i++;
	}
	update_int_coords(points);
}
