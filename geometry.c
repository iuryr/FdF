/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:23:30 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/30 15:49:53 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_meta *meta, int scale)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		j = 0;
		while (j < meta->pt_matrix.cols)
		{
			meta->pt_matrix.data[i][j].x = i * scale;
			meta->pt_matrix.data[i][j].y = j * scale;
			meta->pt_matrix.data[i][j].z = meta->map.data[i][j] * scale;
			j++;
		}
		i++;
	}
}

void	rotation_45dl(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;
	int				x;
	int				y;
	double			theta;

	theta = M_PI / 4;
	i = 0;
	while (i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			x = (pt_matrix->data[i][j].x - WINDOW_WIDTH / 2) * cos(theta)
				- (pt_matrix->data[i][j].y - WINDOW_HEIGHT / 2) * sin(theta);
			y = (pt_matrix->data[i][j].x - WINDOW_WIDTH / 2) * sin(theta)
				+ (pt_matrix->data[i][j].y - WINDOW_HEIGHT / 2) * cos(theta);
			pt_matrix->data[i][j].x = x + WINDOW_WIDTH / 2;
			pt_matrix->data[i][j].y = y + WINDOW_HEIGHT / 2;
			j++;
		}
		i++;
	}
}
