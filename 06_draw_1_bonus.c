/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_draw_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:44:52 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:03:31 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_line(t_point start, t_point end, t_img *img)
{
	if (ft_abs(end.x - start.x) >= ft_abs(end.y - start.y))
		draw_bres_low(start, end, end.color, img);
	else
		draw_bres_high(start, end, end.color, img);
}

//sample X
void	draw_bres_low(t_point start, t_point end, int color, t_img *img)
{
	t_draw_info	info;

	if (end.x - start.x < 0)
	{
		init_draw_info(&info, end, start, color);
		draw_samplex(info, img);
	}
	else
	{
		init_draw_info(&info, start, end, color);
		draw_samplex(info, img);
	}
}

void	draw_samplex(t_draw_info info, t_img *img)
{
	int	yi;
	int	p;

	yi = 1;
	if (info.dy < 0)
	{
		yi = -1;
		info.dy = -info.dy;
	}
	p = 2 * info.dy - info.dx;
	while (info.start.x <= info.end.x)
	{
		img_pix_put(img, info.start.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.y = info.start.y + yi;
			p = p + 2 * (info.dy - info.dx);
		}
		else
			p = p + 2 * info.dy;
		info.start.x++;
	}
}

//sample y
void	draw_bres_high(t_point start, t_point end, int color, t_img *img)
{
	t_draw_info	info;

	if (end.y - start.y < 0)
	{
		init_draw_info(&info, end, start, color);
		draw_sampley(info, img);
	}
	else
	{
		init_draw_info(&info, start, end, color);
		draw_sampley(info, img);
	}
}

void	draw_sampley(t_draw_info info, t_img *img)
{
	int	xi;
	int	p;

	xi = 1;
	if (info.dx < 0)
	{
		xi = -1;
		info.dx = -info.dx;
	}
	p = 2 * info.dx - info.dy;
	while (info.start.y <= info.end.y)
	{
		img_pix_put(img, info.start.x, info.start.y, info.color);
		if (p > 0)
		{
			info.start.x = info.start.x + xi;
			p = p + 2 * (info.dx - info.dy);
		}
		else
			p = p + 2 * info.dx;
		info.start.y++;
	}
}
