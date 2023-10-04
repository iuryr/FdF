/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_keys_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:22:43 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:03:40 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	handle_keypress(int keysym, t_meta *meta)
{
	if (keysym == XK_Escape)
		on_close(meta);
	else if (keysym == XK_Up)
		apply_neg_offset_y(meta);
	else if (keysym == XK_Down)
		apply_pos_offset_y(meta);
	else if (keysym == XK_Right)
		apply_pos_offset_x(meta);
	else if (keysym == XK_Left)
		apply_neg_offset_x(meta);
	else if (keysym == XK_q && meta->pt_matrix.theta_x < M_PI / 6)
		rot_ax(meta, 0.0872665);
	else if (keysym == XK_e && meta->pt_matrix.theta_x > -M_PI / 6)
		rot_ax(meta, -0.0872665);
	else if (keysym == XK_a && meta->pt_matrix.theta_y < M_PI / 8)
		rot_ay(meta, 0.0872665);
	else if (keysym == XK_d && meta->pt_matrix.theta_y > -M_PI / 8)
		rot_ay(meta, -0.0872665);
	else if (keysym == XK_z && meta->pt_matrix.theta_z < M_PI / 6)
		rot_az(meta, 0.0872665);
	else if (keysym == XK_c && meta->pt_matrix.theta_z > -M_PI / 6)
		rot_az(meta, -0.0872665);
	else if (keysym == XK_g)
		zoom(meta, 0.95);
	else if (keysym == XK_h)
		zoom(meta, 1.05);
	else if (keysym == XK_p)
		render_profile(meta);
	else if (keysym == XK_i)
		render_iso(meta);
	return (0);
}
