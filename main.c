/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/19 17:37:54 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_meta	meta;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf map_file_name\n");
		exit(ARGC_ERROR);
	}
	load_map(&meta, argv[1]);
	load_pt_matrix(&meta);
	system_init(&meta);
	img_init(&meta);
	// scale(&meta, 20);
	// rotation_45dl(&meta.pt_matrix);
	// to_iso(&meta.pt_matrix);
	// rot_xy_ac(&meta.pt_matrix, -M_PI / 2);
	update_img(&meta);
	mlx_loop_hook(meta.mlx_ptr, &render, &meta);
	mlx_hook(meta.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &meta);
	mlx_hook(meta.win_ptr, DestroyNotify, NoEventMask, &on_close, &meta);
	mlx_loop(meta.mlx_ptr);
	free_matrix_data(&meta);
	free_map_data(&meta);
	cleanup_graph_resources(&meta);
	return (0);
}
