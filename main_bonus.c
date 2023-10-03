/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:40:11 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char *argv[])
{
	t_meta	meta;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf_bonus map_file_name\n");
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
	init_hooks(&meta);
	mlx_loop(meta.mlx_ptr);
	free_matrix_data(&meta);
	free_map_data(&meta);
	cleanup_graph_resources(&meta);
	return (0);
}
