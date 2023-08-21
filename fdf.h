/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:44 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/21 16:09:13 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"

typedef struct s_map
{
	unsigned int	rows;
	unsigned int	cols;
	int				**data;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* Map parsing functions*/
void	get_map_dimensions(t_map *map, char *filename);
void	alloc_map_data(t_map *map);
void	get_map_data(t_map *map, char *filename);



#endif //_FDF_H_
