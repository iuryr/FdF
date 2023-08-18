/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/18 18:50:48 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_nrows(int map_fd)
{
	char *gnl_return;
	int nrows;

	nrows = 0;
	while ((gnl_return = get_next_line(map_fd)) != NULL)
		nrows++;
	return (nrows);
}

int	get_map_ncols(int map_fd)
{
	char *first_row;
	int	ncols;

	first_row = get_next_line(map_fd);
	ncols = count_word(first_row, ' ');
	return (ncols);
}

int main(void)
{
	int map_fd;
	int	ncols;
	int	nrows;
	t_map	map;

	map_fd = open("maps/test_maps/42.fdf", O_RDONLY);
	ncols = get_map_ncols(map_fd);
	ft_printf("ncols: %i\n", ncols);
	close(map_fd);

	map_fd = open("maps/test_maps/42.fdf", O_RDONLY);
	nrows = get_map_nrows(map_fd);
	ft_printf("nrows: %i\n", nrows);
	close(map_fd);
}
