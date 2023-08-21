/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/21 16:35:53 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	get_map_dimensions(t_map *map, char *filename)
{
	int					fd;
	char				*row;
	unsigned int		nrows;

	fd = open(filename, O_RDONLY);
	row = get_next_line(fd);
	map->cols = count_word(row, ' ');
	free(row);
	nrows = 1;
	row = get_next_line(fd);
	while (row)
	{
		nrows++;
		free(row);
		row = get_next_line(fd);
	}
	map->rows = nrows;
	close(fd);
}

void	alloc_map_data(t_map *map)
{
	unsigned int	i;

	map->data = (int **) malloc(map->rows * sizeof(int *));
	i = 0;
	while (i < map->rows)
	{
		map->data[i] = malloc(map->cols * sizeof(int));
		i++;
	}
}

void	get_map_data(t_map *map, char *filename)
{
	int					fd;
	unsigned int		line;
	unsigned int		col;
	char				*line_content;
	char				**split_line;

	alloc_map_data(map);
	fd = open(filename, O_RDONLY);
	line = 0;
	while (line < map->rows)
	{
		line_content = get_next_line(fd);
		split_line = ft_split(line_content, ' ');
		col = 0;
		while (col < map->cols)
		{
			map->data[line][col] = ft_atoi(split_line[col]);
			free(split_line[col]);
			col++;
		}
		free(split_line);
		free(line_content);
		line++;
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_map		map;

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
