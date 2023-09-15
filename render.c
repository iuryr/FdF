/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:46:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/15 15:01:44 by iusantos         ###   ########.fr       */
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

void	render_points(t_meta *meta, int color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			img_pix_put(meta->img, meta->pt_matrix.data[i][j].y,
				meta->pt_matrix.data[i][j].x, color);
			j++;
		}
		i++;
	}
}

void	render_lines(t_ptmatrix *points, int color, t_img *img)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < points->rows - 1)
	{
		j = 0;
		while (j < points->cols - 1)
		{
			draw_line(points->data[i][j], points->data[i + 1][j], color, img);
			draw_line(points->data[i][j], points->data[i][j + 1], color, img);
			j++;
		}
		draw_line(points->data[i][j], points->data[i + 1][j], color, img);
		i++;
	}
	j = 0;
	while (j < points->cols - 1)
	{
		draw_line(points->data[i][j], points->data[i][j + 1], color, img);
		j++;
	}
}



void	update_px_coords(t_ptmatrix *points)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < points->rows)
	{
		j = 0;
		while (j < points->cols)
		{
			points->data[i][j].x = (int) floor(points->data[i][j].xf);
			points->data[i][j].y = (int) floor(points->data[i][j].yf);
			points->data[i][j].z = (int) floor(points->data[i][j].zf);
			j++;
		}
		i++;
	}
	update_minmax(points);
	update_center(points);
}

void update_img(t_meta *meta)
{
	render_bg(meta->img, WHITE_PIXEL);
	to_iso(&meta->pt_matrix);
	update_px_coords(&meta->pt_matrix);
	render_points(meta, BLUE_PIXEL);
	render_lines(&meta->pt_matrix, RED_PIXEL, meta->img);
	// rot_xy_ac(&meta->pt_matrix, (M_PI  / 4) );
	// render_lines(&meta->pt_matrix, GREEN_PIXEL, meta->img);
	// render_points(meta, BLUE_PIXEL);
}

int	render(t_meta *meta)
{
	if (meta->win_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img,
		50, 50);
	return (0);
}
