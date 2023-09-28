/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_projection_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:08 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 10:59:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(t_ptmatrix *pt_matrix)
{
	rot_az_ac(pt_matrix, M_PI / 4);
	rot_ax_ac(pt_matrix, atan(1 / sqrt(2)));
	update_px_coords(pt_matrix);
}
