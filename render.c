/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:46:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/23 15:03:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_bg(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render(t_meta *meta)
{
	if (meta->win_ptr == NULL)
		return (-1);
	render_bg(meta->img, WHITE_PIXEL);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img,
		0, 0);
	return (0);
}
