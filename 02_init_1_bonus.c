/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:04:15 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/27 15:07:05 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

//init xserver connection & creates window & img, dealing with possible failures
int	system_init(t_meta *meta)
{
	graph_facilities_init(meta);
	win_init(meta);
	img_init(meta);
	return (0);
}

int	graph_facilities_init(t_meta *meta)
{
	meta->mlx_ptr = mlx_init();
	if (meta->mlx_ptr == NULL)
		exit(MLX_INIT_ERROR);
	return (0);
}

int	win_init(t_meta *meta)
{
	meta->win_ptr = mlx_new_window(meta->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "FdF - iusantos");
	if (meta->win_ptr == NULL)
	{
		free(meta->mlx_ptr);
		exit(MLX_WIN_ERROR);
	}
	return (0);
}

//init image & sets elements
int	img_init(t_meta *meta)
{
	meta->img = malloc(sizeof(t_img));
	if (meta->img == NULL)
	{
		free(meta->win_ptr);
		free(meta->mlx_ptr);
		exit(IMG_INIT_ERROR);
	}
	meta->img->mlx_img = mlx_new_image(meta->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	meta->img->addr = mlx_get_data_addr(meta->img->mlx_img, &meta->img->bpp,
			&meta->img->line_len, &meta->img->endian);
	return (0);
}
