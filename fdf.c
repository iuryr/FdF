/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/21 11:08:54 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	get_map_dimensions(t_map *map, char *filename)
{
	int				fd;
	char	*first_row;
	int nrows;
	
	fd = open(filename, O_RDONLY);
	first_row = get_next_line(fd);
	nrows = 1;
	while (get_next_line(fd))
		nrows++;
	map->width = count_word(first_row, ' ');
	map->length = nrows;
	close(fd);
}

int main(int argc, char *argv[])
{
	t_map	map;

	get_map_dimensions(&map, argv[1]);
	printf("width: %i\n", map.width);
	printf("length: %i\n", map.length);


}
