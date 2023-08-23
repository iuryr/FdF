/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/23 14:32:35 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int handle_keypress(int keysym, t_meta *meta)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(meta->mlx_ptr, meta->img->mlx_img);
		mlx_destroy_window(meta->mlx_ptr, meta->win_ptr);
		mlx_destroy_display(meta->mlx_ptr);
		free(meta->img);
		free(meta->mlx_ptr);
		free(meta);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_meta	*meta;
	// t_map		map;
	// unsigned int	i;
	// t_point			*projected_points;

	meta = malloc(sizeof(t_meta));
	if (meta == NULL)
		exit(SYS_ERROR); //mlx error
	system_init(meta);
	img_init(meta);
	if (argc != 2)
		exit(ARGC_ERROR);
	write(1, ++argv, 15);
	mlx_loop_hook(meta->mlx_ptr, &render, meta);
	mlx_hook(meta->win_ptr, KeyPress, KeyPressMask, &handle_keypress, meta);
	mlx_loop(meta->mlx_ptr);

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
