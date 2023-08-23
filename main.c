/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/23 15:23:14 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_meta	meta;
	// t_map		map;
	// unsigned int	i;
	// t_point			*projected_points;

	system_init(&meta);
	img_init(&meta);
	if (argc != 2)
		exit(ARGC_ERROR);
	write(1, ++argv, 15);
	mlx_loop_hook(meta.mlx_ptr, &render, &meta);
	mlx_hook(meta.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &meta);
	mlx_loop(meta.mlx_ptr);

	// get_map_dimensions(&map, argv[1]);
	// get_map_data(&map, argv[1]);
	// projected_points = malloc(map.rows * map.cols * sizeof(t_point));
	// // to_iso(&map, projected_points);
	//
	// unsigned int a = 0;
	// while (a < map.points_count)
	// {
	// 	printf("Ponto %i: x = %f | y = %f\n", a, projected_points[a].x, projected_points[a].y);
	// 	a++;
	// }
	// free(projected_points);
	//
	//
	// // freeing map data to avoid leaks;
	// i = 0;
	// while(i < map.rows)
	// {
	// 	free(map.data[i]);
	// 	i++;
	// }
	// free(map.data);
}
