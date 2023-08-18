/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:50:46 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/18 16:40:54 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_ncols(int map_fd)
{
	char *first_row;
	int	ncols;

	first_row = get_next_line(map_fd);
	ncols = count_word(first_row, ' ');
	return (ncols);
}

int main(int argc, char *argv[])
{
	int map_fd;
	int	ncols;
	map_fd = open("maps/test_maps/42.fdf", O_RDONLY);
	ncols = get_map_ncols(map_fd);
	ft_printf("%i\n", ncols);
	close(map_fd);
	

}
