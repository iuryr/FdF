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
	else if (keysym == XK_q)
		rot_ax(meta, 0.0872665);
	else if (keysym == XK_e)
		rot_ax(meta, -0.0872665);
	else if (keysym == XK_a)
		rot_ay(meta, 0.0872665);
	else if (keysym == XK_d)
		rot_ay(meta, -0.0872665);
	else if (keysym == XK_z)
		rot_az(meta, 0.0872665);
	else if (keysym == XK_c)
		rot_az(meta, -0.0872665);
	return (0);
}
