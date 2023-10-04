/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_render_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:36:43 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 16:40:59 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	update_render(t_meta *meta)
{
	mlx_clear_window(meta->mlx_ptr, meta->win_ptr);
	render_img_bg(meta->img, BLACK_PIXEL);
	render_menu_bg(meta->menu_img, DARK_GREY);
	render_lines(meta->pt_matrix, meta->img);
}

void	render_profile(t_meta *meta)
{
	load_points(meta);
	center_to_og(&meta->pt_matrix);
	to_profile(&meta->pt_matrix);
	scale(&meta->pt_matrix);
	center_to_im(&meta->pt_matrix);
	render_lines(meta->pt_matrix, meta->img);
	meta->re_render = 1;
}

void	render_iso(t_meta *meta)
{
	load_points(meta);
	center_to_og(&meta->pt_matrix);
	to_iso(&meta->pt_matrix);
	scale(&meta->pt_matrix);
	center_to_im(&meta->pt_matrix);
	render_lines(meta->pt_matrix, meta->img);
	meta->re_render = 1;
}

void	render_menu(t_meta *meta)
{
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 10, WHITE_PIXEL,
		"FDF - iusantos");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 30, WHITE_PIXEL,
		"ARROWS: TRANSLATION");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 50, WHITE_PIXEL,
		"Q/E: Rotation X");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 70, WHITE_PIXEL,
		"A/D: Rotation Y");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 90, WHITE_PIXEL,
		"Z/C: Rotation Z");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 110, WHITE_PIXEL,
		"G/H : Zoom In and Out");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 130, WHITE_PIXEL,
		"P: Profile Projection");
	mlx_string_put(meta->mlx_ptr, meta->win_ptr, 10, 150, WHITE_PIXEL,
		"I: Reset Isometric Projection");
}
