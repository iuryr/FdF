/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:13:33 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/15 14:36:17 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	determine_scale(t_map map)
{
	int	scale_x;
	int	scale_y;

	scale_x = WINDOW_WIDTH / map.cols;
	scale_y = WINDOW_HEIGHT / map.rows;
	if (scale_x <= scale_y)
		return (scale_x);
	else
		return (scale_y);
}
