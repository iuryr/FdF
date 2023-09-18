/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:08 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/15 14:27:41 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(t_ptmatrix *pt_matrix)
{
	rot_ay_ac(pt_matrix, -M_PI / 4);
	rot_ax_ac(pt_matrix, -0.615472907);
}
