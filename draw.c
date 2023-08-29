/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:44:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/29 14:18:20 by iusantos         ###   ########.fr       */
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

void	draw_line(t_point start, t_point end, int color, t_img *img)
{
	t_draw_info	info;

	init_draw_info(&info, start, end, color);
	if (info.dx == 0 & info.dy != 0)
		draw_hline(info, img);
	if (info.dy == 0 & info.dx != 0)
		draw_vline(info, img);
	if (ft_abs(info.slope) == 1)
		draw_dline(info, img);
	// if (ft_abs(info.dx) > ft_abs(info.dy))
	// 	draw_xsample_line(start, end, color, img);
	// if (ft_abs(info.dx) < ft_abs(info.dy))
	// 	draw_ysample_line(start, end, color, img);
}

void	draw_hline(t_draw_info info, t_img *img)
{
	int	i;

	if (info.dy > 0)
	{
		i = info.start.y;
		while (i <= info.end.y)
			img_pix_put(img, i++, info.start.x, info.color);
	}
	else
	{
		i = info.start.y;
		while (i >= info.end.y)
			img_pix_put(img, i--, info.start.x, info.color);
	}
}

void	draw_vline(t_draw_info info, t_img *img)
{
	int	i;

	if (info.dx > 0)
	{
		i = info.start.x;
		while (i <= info.end.x)
			img_pix_put(img, info.start.y, i++, info.color);
	}
	else
	{
		i = info.start.y;
		while (i >= info.end.y)
			img_pix_put(img, info.start.y, i--, info.color);
	}
}

void	draw_dline(t_draw_info info, t_img *img)
{
	int	i;
	int	j;

	i = info.start.x;
	j = info.start.y;
	if (info.dy > 0 & info.dx > 0)
		while (i != info.end.x)
			img_pix_put(img, i++, j++, info.color);
	if (info.dy < 0 & info.dx < 0)
		while (i != info.end.x)
			img_pix_put(img, i--, j--, info.color);
	if (info.dx / info.dy == -1 && info.dx > info.dy)
		while (i != info.end.x)
			img_pix_put(img, i++, j--, info.color);
	if (info.dx / info.dy == -1 && info.dx < info.dy)
		while (i != info.end.x)
			img_pix_put(img, i--, j++, info.color);
}
