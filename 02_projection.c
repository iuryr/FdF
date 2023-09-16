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
	unsigned int	i;
	unsigned int	j;
	float x;
	float y;

	i = 0;
	while(i < pt_matrix->rows)
	{
		j = 0;
		while (j < pt_matrix->cols)
		{
			x = 1 / sqrt(2) * (pt_matrix->data[i][j].xf - pt_matrix->data[i][j].zf);
			y =  pt_matrix->data[i][j].xf - 2*pt_matrix->data[i][j].yf + pt_matrix->data[i][j].zf;
			pt_matrix->data[i][j].xf = x;
			pt_matrix->data[i][j].yf = y;
			j++;
		}
		i++;
	}
}
