/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_draw_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:13:25 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/27 16:11:42 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ((x < 0 || x > WINDOW_WIDTH) || (y < 0 || y > WINDOW_HEIGHT))
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

unsigned int	ft_abs(int number)
{
	if (number < 0)
		return (number * -1);
	return (number);
}

void	init_draw_info(t_draw_info *info, t_point start, t_point end, int color)
{
	info->start = start;
	info->end = end;
	info->dx = end.x - start.x;
	info->dy = end.y - start.y;
	info->slope = (float) info->dy / (float) info->dx;
	info->color = color;
}
