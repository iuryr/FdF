/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 17:54:29 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_meta	meta;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf map_file_name.fdf\n");
		exit(ARGC_ERROR);
	}
	if (load_map(&meta, argv[1]) != 0)
	{
		ft_printf("Problem opening map file. Exiting.\n");
		exit(FILDE_ERROR);
	}
	load_pt_matrix(&meta);
	system_init(&meta);
	prepare_first_render(&meta);
	mlx_loop_hook(meta.mlx_ptr, &render, &meta);
	mlx_hook(meta.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &meta);
	mlx_hook(meta.win_ptr, DestroyNotify, NoEventMask, &on_close, &meta);
	mlx_loop(meta.mlx_ptr);
	free_matrix_data(&meta);
	free_map_data(&meta);
	cleanup_graph_resources(&meta);
	return (0);
}
