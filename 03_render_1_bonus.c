/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_render_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:46:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:03:10 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	render_img_bg(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < IMG_HEIGHT)
	{
		j = 0;
		while (j < IMG_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

void	render_menu_bg(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MENU_HEIGHT)
	{
		j = 0;
		while (j < MENU_WIDTH)
			img_pix_put(img, j++, i, color);
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

void	prepare_first_render(t_meta *meta)
{
	render_img_bg(meta->img, BLUE_PIXEL);
	render_menu_bg(meta->menu_img, RED_PIXEL);
	center_to_og(&meta->pt_matrix);
	to_iso(&meta->pt_matrix);
	scale(&meta->pt_matrix);
	center_to_im(&meta->pt_matrix);
	render_lines(meta->pt_matrix, meta->img);
}

void	update_render(t_meta *meta)
{
	mlx_clear_window(meta->mlx_ptr, meta->win_ptr);
	render_img_bg(meta->img, BLUE_PIXEL);
	render_menu_bg(meta->menu_img, RED_PIXEL);
	render_lines(meta->pt_matrix, meta->img);
}


void	render_menu(t_meta *meta)
{
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 10, WHITE_PIXEL, "FDF - iusantos");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 30, WHITE_PIXEL, "ARROWS: TRANSLATION");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 50, WHITE_PIXEL, "Q/E : Rotation X");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 70, WHITE_PIXEL, "A/D : Rotation Y");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 90, WHITE_PIXEL, "Z/C : Rotation Z");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 110, WHITE_PIXEL, "G/H : Zoom In and Out");
}

int	render(t_meta *meta)
{
	if (meta->win_ptr == NULL)
		return (-1);
	if (meta->re_render == 1)
		update_render(meta);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->menu_img->mlx_img,
		0, 0);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img,
		MENU_WIDTH, 0);
	render_menu(meta);
	meta->re_render = 0;
	return (0);
}
