/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/29 14:18:40 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_meta	meta;

	if (argc != 2)
		exit(ARGC_ERROR);
	load_map(&meta, argv[1]);
	pt_matrix_init(&meta);
	alloc_ptmatrix_data(&meta.pt_matrix);
	system_init(&meta);
	scale(&meta, 20);
	// rotation_45dl(&meta.pt_matrix);
	img_init(&meta);
	mlx_loop_hook(meta.mlx_ptr, &render, &meta);
	mlx_hook(meta.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &meta);
	mlx_loop(meta.mlx_ptr);
}
