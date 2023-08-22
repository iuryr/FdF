/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/22 10:18:42 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_matrix		map;

	if (argc != 2)
		return (1);
	get_map_dimensions(&map, argv[1]);
	printf("cols: %i\n", map.cols);
	printf("rows: %i\n", map.rows);
	get_map_data(&map, argv[1]);
	unsigned int i = 0;
	unsigned int j;
	while (i < map.rows)
	{
		j = 0;
		while (j < map.cols)
		{
			printf("%i ", map.data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// freeing map data to avoid leaks;
	i = 0;
	while(i < map.rows)
	{
		free(map.data[i]);
		i++;
	}
	free(map.data);
}
