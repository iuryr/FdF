/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsemap_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:52:55 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 18:03:46 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	load_map(t_meta *meta, char *filename)
{
	if (ft_strnstr(filename, ".fdf", 1024) == NULL)
	{
		ft_printf("File extension is not proper.\n");
		exit(ARGC_BAD_XT);
	}
	if (get_map_dimensions(&meta->map, filename) != 0)
		return (1);
	alloc_map_data(&meta->map);
	if (get_map_data(&meta->map, filename) != 0)
		return (1);
	return (0);
}

int	get_map_dimensions(t_map *map, char *filename)
{
	int					fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	get_map_cols(map, fd);
	get_map_rows(map, fd);
	map->points_count = map->rows * map->cols;
	close(fd);
	return (0);
}

void	alloc_map_data(t_map *map)
{
	unsigned int	i;

	map->data = malloc(map->rows * sizeof(char **));
	i = 0;
	while (i < map->rows)
	{
		map->data[i] = malloc(map->cols * sizeof(char *));
		i++;
	}
}

int	get_map_data(t_map *map, char *filename)
{
	int					fd;
	unsigned int		line;
	unsigned int		col;
	char				*line_content;
	char				**split_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = -1;
	while (++line < map->rows)
	{
		line_content = gnl_wo_nl(fd);
		split_line = ft_split(line_content, ' ');
		col = -1;
		while (++col < map->cols)
		{
			map->data[line][col] = ft_strdup(split_line[col]);
			free(split_line[col]);
		}
		free(split_line);
		free(line_content);
	}
	close(fd);
	return (0);
}
