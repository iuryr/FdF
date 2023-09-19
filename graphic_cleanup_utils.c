/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_cleanup_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:15:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/19 18:03:16 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_matrix_data(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->pt_matrix.rows)
	{
		free(meta->pt_matrix.data[i]);
		i++;
	}
	free(meta->pt_matrix.data);
	return (0);
}

int	free_map_data(t_meta *meta)
{
	unsigned int	i;

	i = 0;
	while (i < meta->map.rows)
	{
		free(meta->map.data[i]);
		i++;
	}
	free(meta->map.data);
	return (0);
}

int	cleanup_graph_resources(t_meta *meta)
{
	mlx_destroy_image(meta->mlx_ptr, meta->img->mlx_img);
	mlx_destroy_window(meta->mlx_ptr, meta->win_ptr);
	mlx_destroy_display(meta->mlx_ptr);
	free(meta->img);
	free(meta->mlx_ptr);
	return (0);
}

int	on_close(t_meta *meta)
{
	free_matrix_data(meta);
	free_map_data(meta);
	cleanup_graph_resources(meta);
	return(0);
}
