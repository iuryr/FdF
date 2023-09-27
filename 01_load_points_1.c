/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_load_points_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:38 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/27 14:50:31 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_pt_matrix(t_meta *meta)
{
	pt_matrix_init(meta);
	alloc_ptmatrix_data(&meta->pt_matrix);
	load_points(meta);
}

void	pt_matrix_init(t_meta *meta)
{
	meta->pt_matrix.rows = meta->map.rows;
	meta->pt_matrix.cols = meta->map.cols;
}

void	alloc_ptmatrix_data(t_ptmatrix *pt_matrix)
{
	unsigned int	i;

	pt_matrix->data = (t_point **) malloc(pt_matrix->rows * sizeof(t_point *));
	i = 0;
	while (i < pt_matrix->rows)
	{
		pt_matrix->data[i] = malloc(pt_matrix->cols * sizeof(t_point));
		i++;
	}
}

void	load_points(t_meta *meta)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].x = j;
			meta->pt_matrix.data[i][j].y = i;
			meta->pt_matrix.data[i][j].z = ft_atoi(meta->map.data[i][j]);
			get_color(meta, i, j);
			j++;
		}
		i++;
	}
	set_minmax(&meta->pt_matrix);
	update_minmax(&meta->pt_matrix);
	update_center(&meta->pt_matrix);
	set_float_coords(&meta->pt_matrix);
}
