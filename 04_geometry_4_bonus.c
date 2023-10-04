/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_geometry_4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:16:22 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 17:18:38 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	apply_pos_offset_y(t_meta *meta)
{
	unsigned int	i;
	unsigned int	j;

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
	unsigned int	i;
	unsigned int	j;

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
	unsigned int	i;
	unsigned int	j;

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
