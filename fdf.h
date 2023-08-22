/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:44 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/22 10:18:57 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"

typedef struct s_matrix
{
	unsigned int	rows;
	unsigned int	cols;
	int				**data;
}	t_matrix;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

/* Map parsing functions*/
void	get_map_dimensions(t_matrix *map, char *filename);
void	alloc_map_data(t_matrix *map);
void	get_map_data(t_matrix *map, char *filename);



#endif //_FDF_H_
