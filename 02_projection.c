/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:22:08 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/29 15:18:51 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_iso(t_ptmatrix *pt_matrix)
{
	unsigned int	i;
	unsigned int	j;
	int x;
	int y;

	i = 0;
	while(i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			x = 1 / sqrt(2) * (pt_matrix->data[i][j].x - pt_matrix->data[i][j].z);
			y =  pt_matrix->data[i][j].x - 2*pt_matrix->data[i][j].y + pt_matrix->data[i][j].z;
			pt_matrix->data[i][j].x = x;
			pt_matrix->data[i][j].y = y;
			j++;
		}
		i++;
	}
}
