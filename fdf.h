/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:44 by iusantos          #+#    #+#             */
/*   Updated: 2023/08/23 15:05:32 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include <X11/keysym.h> //macros com definição de teclas
# include <X11/X.h> //macros com definição de events e masks

# define SYS_ERROR 1
# define MLX_INIT_ERROR 21
# define MLX_WIN_ERROR 22
# define ARGC_ERROR 3
# define IMG_INIT_ERROR 4

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define BLUE_PIXEL 0x0000FF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_meta
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}	t_meta;

typedef struct s_map
{
	unsigned int	rows;
	unsigned int	cols;
	unsigned int	points_count;
	int				**data;
}	t_map;

typedef struct s_matrix
{
	int	rows;
	int	cols;
	int	**data;
}	t_matrix;

typedef struct s_point
{
	double	x;
	double	y;
	int		color;
}	t_point;

typedef struct s_line
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	int	color;
}	t_line;

/* Initialization functions */
void	system_init(t_meta *meta);
void	img_init(t_meta *meta);

/* Map parsing functions */
void	get_map_dimensions(t_map *map, char *filename);
void	alloc_map_data(t_map *map);
void	get_map_data(t_map *map, char *filename);

/* Drawing functions */
void	img_pix_put(t_img *img, int x, int y, int color);

/* Rendering Functions */
int		render(t_meta *meta);
void	render_bg(t_img *img, int color);

#endif //_FDF_H_
