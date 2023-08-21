/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/21 12:02:53 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	get_map_dimensions(t_map *map, char *filename)
{
	int		fd;
	char	*row;
	int		nrows;

	fd = open(filename, O_RDONLY);
	row = get_next_line(fd);
	map->width = count_word(row, ' ');
	free(row);
	nrows = 1;
	while ((row = get_next_line(fd)))
	{
		nrows++;
		free(row);
	}
	map->length = nrows;
	close(fd);
	return;
}



int	main(int argc, char *argv[])
{
	t_map	map;

	get_map_dimensions(&map, argv[1]);
	printf("width: %i\n", map.width);
	printf("length: %i\n", map.length);
}
