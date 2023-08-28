/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:44:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/28 15:55:15 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	draw_line(t_point start, t_point end, int color, t_img *img)
{
	int		dx;
	int		dy;
	float	slope;

	dx = end.x - start.x;
	dy = end.y - start.y;
	slope = (float) dx / (float) dy;
	if (dx == 0 & dy != 0)
		draw_hline(start, end, color, img);
	if (dy == 0 & dx != 0)
		draw_vline(start, end, color, img);
	if (ft_abs(slope) == 1)
		draw_dline(start, end, color, img);
}

void	draw_hline(t_point start, t_point end, int color, t_img *img)
{
	int	dy;
	int	i;

	dy = end.y - start.y;
	if (dy > 0)
	{
		i = start.y;
		while (i <= end.y)
			img_pix_put(img, i++, start.x, color);
	}
	else
	{
		i = start.y;
		while (i >= end.y)
			img_pix_put(img, i--, start.x, color);
	}
}

void	draw_vline(t_point start, t_point end, int color, t_img *img)
{
	int	dx;
	int	i;

	dx = end.x - start.x;
	if (dx > 0)
	{
		i = start.x;
		while (i <= end.x)
			img_pix_put(img, start.y, i++, color);
	}
	else
	{
		i = start.y;
		while (i >= end.y)
			img_pix_put(img, start.y, i--, color);
	}
}

void	draw_dline(t_point start, t_point end, int color, t_img *img)
{
	int	dx;
	int	dy;
	int	i;
	int	j;

	dx = end.x - start.x;
	dy = end.y - start.y;
	i = start.x;
	j = start.y;
	if (dy > 0 & dx > 0)
		while (i != end.x)
			img_pix_put(img, i++, j++, color);
	if (dy < 0 & dx < 0)
		while (i != end.x)
			img_pix_put(img, i--, j--, color);
	if (dx / dy == -1 && dx > dy)
		while (i != end.x)
			img_pix_put(img, i++, j--, color);
	if (dx / dy == -1 && dx < dy)
		while (i != end.x)
			img_pix_put(img, i--, j++, color);
}
