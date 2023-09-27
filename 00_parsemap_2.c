/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parsemap_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:26:57 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/27 14:51:11 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	count_cols(char *line)
{
	int	cols;

	cols = count_word(line, ' ');
	return (cols);
}

char	*gnl_wo_nl(int fd)
{
	char	*line;
	char	*s;

	line = get_next_line(fd);
	if (line)
	{
		s = ft_strtrim(line, "\n");
		free(line);
		return (s);
	}
	return (NULL);
}

void	get_map_cols(t_map *map, int fd)
{
	char	*row;

	row = gnl_wo_nl(fd);
	map->cols = count_cols(row);
	free(row);
}

void	get_map_rows(t_map *map, int fd)
{
	unsigned int	nrows;
	char			*row;

	nrows = 1;
	row = gnl_wo_nl(fd);
	while (row)
	{
		if (count_cols(row) != map->cols)
		{
			free(row);
			row = gnl_wo_nl(fd);
			while (row)
			{
				free(row);
				row = gnl_wo_nl(fd);
			}
			ft_printf("Map file dimensions are not proper. Exiting.\n");
			exit(MAP_DIM_ERROR);
		}
		nrows++;
		free(row);
		row = gnl_wo_nl(fd);
	}
	map->rows = nrows;
}
