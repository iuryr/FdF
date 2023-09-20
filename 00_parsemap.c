/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsemap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:52:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/28 13:27:57 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

void	load_map(t_meta *meta, char *filename)
{
	get_map_dimensions(&meta->map, filename);
	alloc_map_data(&meta->map);
	get_map_data(&meta->map, filename);
}

void	get_map_dimensions(t_map *map, char *filename)
{
	int					fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
		exit(FILDE_ERROR);
	get_map_cols(map, fd);
	get_map_rows(map, fd);
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

	fd = open(filename, O_RDONLY);
	line = 0;
	while (line < map->rows)
	{
		line_content = gnl_wo_nl(fd);
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
