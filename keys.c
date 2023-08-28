/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:22:43 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/28 13:25:09 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_meta *meta)
{
	unsigned int	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		while (i < meta->pt_matrix.rows)
		{
			free(meta->pt_matrix.data[i]);
			i++;
		}
		free(meta->pt_matrix.data);
		i = 0;
		while (i < meta->map.rows)
		{
			free(meta->map.data[i]);
			i++;
		}
		free(meta->map.data);
		mlx_destroy_image(meta->mlx_ptr, meta->img->mlx_img);
		mlx_destroy_window(meta->mlx_ptr, meta->win_ptr);
		mlx_destroy_display(meta->mlx_ptr);
		free(meta->img);
		free(meta->mlx_ptr);
		exit(0);
	}
	return (0);
}
