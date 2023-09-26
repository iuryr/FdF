/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:46:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/26 17:03:16 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_bg(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

void	render_points(t_ptmatrix pt_matrix, int color, t_img *img)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < pt_matrix.rows)
	{
		j = 0;
		while (j < pt_matrix.cols)
		{
			img_pix_put(img, pt_matrix.data[i][j].x,
				pt_matrix.data[i][j].y, color);
			j++;
		}
		i++;
	}
}

void	render_lines(t_ptmatrix points, t_img *img)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points.rows - 1)
	{
		j = 0;
		while (j < points.cols - 1)
		{
			draw_line(points.data[i][j], points.data[i + 1][j], img);
			draw_line(points.data[i][j], points.data[i][j + 1], img);
			j++;
		}
		draw_line(points.data[i][j], points.data[i + 1][j], img);
		i++;
	}
	j = 0;
	while (j < points.cols - 1)
	{	
		draw_line(points.data[i][j], points.data[i][j + 1], img);
		j++;
	}
}



void	update_px_coords(t_ptmatrix *points)
{
	update_int_coords(points);
	update_minmax(points);
	update_center(points);
}

void update_img(t_meta *meta)
{
	t_ptmatrix	to_render;

	to_render = meta->pt_matrix;
	render_bg(meta->img, BLACK_PIXEL);
	center_to_og(&to_render);
	to_iso(&to_render);
	scale(&to_render);
	center_to_wm(&to_render);
	render_lines(to_render, meta->img);
}

int	render(t_meta *meta)
{
	if (meta->win_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img,
		0, 0);
	return (0);
}
