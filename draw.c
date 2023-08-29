/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:44:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/29 15:12:54 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_point start, t_point end, int color, t_img *img)
{
	t_draw_info	info;

	init_draw_info(&info, start, end, color);
	if (info.dx == 0 & info.dy != 0)
		draw_hline(info, img);
	else if (info.dy == 0 & info.dx != 0)
		draw_vline(info, img);
	else if (ft_abs(info.slope) == 1)
		draw_dline(info, img);
	else if (ft_abs(info.dx) > ft_abs(info.dy))
	 	draw_bres_low(info, img);
	else if (ft_abs(info.dx) < ft_abs(info.dy))
		draw_bres_high(info, img);
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

void	draw_bres_low(t_draw_info info, t_img *img)
{
	if (info.dx < 0)
	{
		draw_samplex_e2s(info, img);
	}
	else
		draw_samplex_s2e(info, img);
}

void	draw_samplex_s2e(t_draw_info info, t_img *img)
{
	int	yi;
	int p;

	yi = 1;
	if (info.dy < 0)
	{
		yi = -1;
		info.dy = -1 * info.dy;
	}
	p = 2 * info.dy - info.dx;
	while (info.start.x++ < info.end.x)
	{
		img_pix_put(img, info.start.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.y = info.start.y + yi;
			p = p + 2 * (info.dy - info.dx);
		}
		else
			p = p + 2 * info.dy;
	}
}

void	draw_samplex_e2s(t_draw_info info, t_img *img)
{
	int	yi;
	int p;

	yi = 1;
	if (info.dy < 0)
	{
		yi = -1;
		info.dy = -1 * info.dy;
	}
	p = 2 * info.dy - info.dx;
	while (info.end.x++ < info.start.x)
	{
		img_pix_put(img, info.end.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.y = info.start.y + yi;
			p = p + 2 * (info.dy - info.dx);
		}
		else
			p = p + 2 * info.dy;
	}

}

void	draw_bres_high(t_draw_info info, t_img *img)
{
	if (info.dy < 0)
	{
		draw_sampley_e2s(info, img);
	}
	else
		draw_sampley_s2e(info, img);
}

void	draw_sampley_s2e(t_draw_info info, t_img *img)
{
	int	xi;
	int p;

	xi = 1;
	if (info.dx < 0)
	{
		xi = -1;
		info.dx = -1 * info.dx;
	}
	p = 2 * info.dx - info.dy;
	while (info.start.y++ < info.end.y)
	{
		img_pix_put(img, info.start.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.x = info.start.x + xi;
			p = p + 2 * (info.dx - info.dy);
		}
		else
			p = p + 2 * info.dx;
	}
}

void	draw_sampley_e2s(t_draw_info info, t_img *img)
{
	int	xi;
	int p;

	xi = 1;
	if (info.dx < 0)
	{
		xi = -1;
		info.dx = -1 * info.dx;
	}
	p = 2 * info.dx - info.dy;
	while (info.end.y++ < info.start.y)
	{
		img_pix_put(img, info.end.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.x = info.start.x + xi;
			p = p + 2 * (info.dx - info.dy);
		}
		else
			p = p + 2 * info.dx;
	}
}
