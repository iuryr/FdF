/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:52:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/23 15:48:50 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_map(t_meta *meta, char *filename)
{
	get_map_dimensions(&meta->map, filename);
	alloc_map_data(&meta->map);
	get_map_data(&meta->map, filename);
}

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
	map->points_count = map->rows * map->cols;
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
