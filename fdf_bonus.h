/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:44 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/27 16:21:43 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"
# include <X11/keysym.h> //macros com definição de teclas
# include <X11/X.h> //macros com definição de events e masks

# define SYS_ERROR 1
# define FILDE_ERROR 11
# define MLX_INIT_ERROR 21
# define MLX_WIN_ERROR 22
# define ARGC_ERROR 3
# define IMG_INIT_ERROR 4
# define PTS_INIT_ERROR 5
# define MAP_DIM_ERROR 6

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define IMG_WIDTH 1000
# define IMG_HEIGHT 800
# define MENU_WIDTH 200
# define MENU_HEIGHT 800

# define DEFAULT_COLOR 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x00FF00
# define WHITE_PIXEL 0xFFFFFF
# define BLUE_PIXEL 0x0000FF
# define BLACK_PIXEL 0x000000

typedef struct s_trig
{
	float	cosa;
	float	sina;
}	t_trig;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	unsigned int	rows;
	unsigned int	cols;
	unsigned int	points_count;
	char			***data;
}	t_map;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	float	xf;
	float	yf;
	float	zf;
	int		color;
}	t_point;

typedef struct s_ptmatrix
{
	unsigned int	rows;
	unsigned int	cols;
	int				x_min;
	int				x_max;
	int				x_range;
	int				y_min;
	int				y_max;
	int				y_range;
	int				x_c;
	int				y_c;
	int				x_offset;
	int				y_offset;
	float			scale;
	t_point			**data;
}	t_ptmatrix;

typedef struct s_draw_info
{
	t_point	start;
	t_point	end;
	int		dx;
	int		dy;
	int		color;
	float	slope;
}	t_draw_info;

typedef struct s_meta
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_img		*menu_img;
	t_map		map;
	t_ptmatrix	pt_matrix;
}	t_meta;

typedef struct s_line
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
	int	color;
}	t_line;

/* Initialization functions */
int				system_init(t_meta *meta);
int				graph_facilities_init(t_meta *meta);
int				win_init(t_meta *meta);
int				img_init(t_meta *meta);
int				menu_img_init(t_meta *meta);

/* Map parsing functions */
int				load_map(t_meta *meta, char *filename);
int				get_map_dimensions(t_map *map, char *filename);
void			alloc_map_data(t_map *map);
int				get_map_data(t_map *map, char *filename);
void			get_map_cols(t_map *map, int fd);
void			get_map_rows(t_map *map, int fd);
char			*gnl_wo_nl(int fd);

/* Loading points coordinates function */
void			load_pt_matrix(t_meta *meta);
void			pt_matrix_init(t_meta *meta);
void			alloc_ptmatrix_data(t_ptmatrix *pt_matrix);
void			determine_scale(t_ptmatrix *points);
void			determine_range(t_ptmatrix *points);
void			set_minmax(t_ptmatrix *points);
void			update_minmax(t_ptmatrix *points);
void			update_center(t_ptmatrix *points);
void			update_int_coords(t_ptmatrix *points);
void			update_px_coords(t_ptmatrix *points);
void			set_float_coords(t_ptmatrix *points);
void			load_points(t_meta *meta);
void			get_color(t_meta *meta, unsigned int line, unsigned int col);
void			set_default_color(t_meta *meta, unsigned int line,
					unsigned int col);
int				fdf_atox(const char *s);

/* Geometry functions*/
void			scale(t_ptmatrix *pt_matrix);
void			center_to_im(t_ptmatrix *pt_matrix);
void			center_to_og(t_ptmatrix *points);
void			og_to_center(t_ptmatrix *points);
void			init_trig(t_trig *angle, float theta);
void			rot_az_ac(t_ptmatrix *points, float theta);
void			rot_ay_ac(t_ptmatrix *points, float theta);
void			rot_ax_ac(t_ptmatrix *points, float theta);
void			rotation_45dl(t_ptmatrix *pt_matrix); //candidata a ser limada
void			to_iso(t_ptmatrix *pt_matrix);

/* Drawing functions */
void			img_pix_put(t_img *img, int x, int y, int color);
void			draw_line(t_point start, t_point end, t_img *img);
void			draw_bres_low(t_point start, t_point end,
					int color, t_img *img);
void			draw_samplex(t_draw_info info, t_img *img);
void			draw_bres_high(t_point start, t_point end,
					int color, t_img *img);
void			draw_sampley(t_draw_info info, t_img *img);
void			init_draw_info(t_draw_info *info, t_point start,
					t_point end, int color);
unsigned int	ft_abs(int number);

/* Rendering Functions */
void			prepare_first_render(t_meta *meta);
int				render(t_meta *meta);
void	render_img_bg(t_img *img, int color);
void	render_menu_bg(t_img *img, int color);
void			render_lines(t_ptmatrix points, t_img *img);

/* Key pressing & releasing*/
int				handle_keypress(int keysym, t_meta *meta);

/* Graphics facilities cleanup utilities */
int				free_matrix_data(t_meta *meta);
int				free_map_data(t_meta *meta);
int				cleanup_graph_resources(t_meta *meta);
int				on_close(t_meta *meta);

#endif //_FDF_BONUS_H_
