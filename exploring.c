#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h> //macros com definição de teclas
#include <X11/X.h> //macros com definição de events e masks
#include <math.h>

#define WINDOW_WIDTH 800
#define	WINDOW_HEIGHT 800

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define	GREEN_PIXEL 0x00FF00
#define	WHITE_PIXEL 0xFFFFFF
#define	BLUE_PIXEL 0x0000FF

//t_line data type
typedef struct s_line
{
	int x_start;
	int y_start;
	int x_end;
	int y_end;
	int color;
} t_line;

//t_img data tyoe
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; //bits per pixel
	int		line_len;
	int		endian;
} t_img;

//data about xserver connection, window, etc
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img	img;
}	t_data;

// x & y in the rect corresponds to upper left corner
typedef struct s_rect
{
	int x;
	int y;
	int width;
	int height;
	int color;
} t_rect;

int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	else
		return (number * -1);
}


int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		exit(0);
	}

	printf("Keypress: %d\n", keysym);
	return (0);
}

int handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void draw_h_line(t_img *img, t_line line)
{
	int i;
	int dx = line.x_end - line.x_start;
	i = line.x_start;

	while (i != line.x_end)
	{
		img_pix_put(img, i, line.y_start, line.color);
		if (dx < 0)
			i--;
		else
			i++;
	}
}

void draw_v_line(t_img *img, t_line line)
{
	int j;
	int dy = line.y_end - line.y_start;
	j = line.y_start;

	while (j != line.y_end)
	{
		img_pix_put(img, line.x_start, j, line.color);
		if (dy < 0)
			j--;
		else
			j++;
	}
}

void draw_d_line(t_img *img, t_line line)
{
	int dx = line.x_end - line.x_start;
	int dy = line.y_end - line.y_start;
	int i;
	int j;

	i = line.x_start;
	j = line.y_start;

	if (dx / dy == 1 && dx > 0 && dy > 0)
	{
		while (i != line.x_end)
		{
			img_pix_put(img, i, j, line.color);
			i++;
			j++;
		}
	}
	if (dx / dy == 1 && dx < 0 && dy < 0)
	{
		while (i != line.x_end)
		{
			img_pix_put(img, i, j, line.color);
			i--;
			j--;
		}
	}
	if (dx / dy == -1 && dx > dy)
	{
		while (i != line.x_end && j != line.y_end)
		{
			img_pix_put(img, i, j, line.color);
			i++;
			j--;
		}
	}
	if (dx / dy == -1 && dx < dy)
	{
		while (i != line.x_end && j != line.y_end)
		{
			img_pix_put(img, i, j, line.color);
			i--;
			j++;
		}
	}
		
}

void draw_xsample_line(t_img *img, t_line line)
{
	int dx = line.x_end - line.x_start;
	int dy = line.y_end - line.y_start;
	int i;
	int j;
	int p;
	int y_increment;

	y_increment = 1;

	p = 2 * dy - dx;

	i = line.x_start;
	j = line.y_start;

	if (dy < 0)
	{
		y_increment = -1;
		dy = -1 * dy;
	}
	while (i <= line.x_end)
	{
		img_pix_put(img, i, j, line.color);
		i++;

		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy - 2 * dx;
			j = j + y_increment;
		}
	}
}

void draw_ysample_line(t_img *img, t_line line)
{
	int dx = line.x_end - line.x_start;
	int dy = line.y_end - line.y_start;
	int i;
	int j;
	int p;
	int x_increment;

	x_increment = 1;

	p = 2 * dx - dy;

	i = line.x_start;
	j = line.y_start;

	if (dx < 0)
	{
		x_increment = -1;
		dx = -1 * dx;
	}

	while (j <= line.y_end)
	{
		img_pix_put(img, i, j, line.color);
		j++;

		if (p < 0)
			p = p + 2 * dx;
		else
		{
			p = p + 2 * dx - 2 * dy;
			i = i + x_increment;
		}
	}
}

t_line rotate_45dl(t_line og_line)
{	
	double theta;
	theta = M_PI / 4 ;

	t_line rotated_line;
	rotated_line.x_start = floor((og_line.x_start - 100) * cos(theta) - (og_line.y_start - 150) * sin(theta)) + 100 ;  
	rotated_line.y_start = floor((og_line.x_start -100) * sin(theta) + (og_line.y_start -150) * cos(theta)) + 150 ;  
	rotated_line.x_end = floor((og_line.x_end -100) * cos(theta) - (og_line.y_end - 150) * sin(theta)) + 100;  
	rotated_line.y_end = floor((og_line.x_end - 100) * sin(theta) + (og_line.y_end - 150) * cos(theta)) + 150 ; 
	rotated_line.color = GREEN_PIXEL;

	return (rotated_line);

}

int	render_line(t_img *img, t_line line)
{
	int dx = line.x_end - line.x_start;
	int dy = line.y_end - line.y_start;

	if (dx == 0)
		draw_v_line(img, line);
	else if (dy == 0)
		draw_h_line(img, line);
	else if (ft_abs(dx) == ft_abs(dy))
		draw_d_line(img, line);
	else if (ft_abs(dx) > ft_abs(dy))
		draw_xsample_line(img, line);
	else if (ft_abs(dx) < ft_abs(dy))
		draw_ysample_line(img, line);
	return (0);
}


int render_rect(t_img *img, t_rect rect)
{
	int i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_bg(t_img *img, int color)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (-1);

	render_bg(&data->img, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){200, 200, 400, 400, GREEN_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	// render_line(&data->img, (t_line){30, 0, 30, 200, RED_PIXEL}); //vline
	// render_line(&data->img, (t_line){30, 200, 300, 200, RED_PIXEL}); //hline
	// render_line(&data->img, (t_line){400, 400, 500, 500, RED_PIXEL});//d positiva
	// render_line(&data->img, (t_line){400, 400, 500, 300, RED_PIXEL});//d negativa
	// render_line(&data->img, (t_line){0, 0, 400, 50, GREEN_PIXEL}); //x sample positive slope
	// render_line(&data->img, (t_line){0, 0, 50, 400, BLUE_PIXEL}); //y sample positive slope
	// render_line(&data->img, (t_line){400, 50, 800, 0, GREEN_PIXEL}); //x sample negative slope
	// render_line(&data->img, (t_line){50, 400, 0, 800, BLUE_PIXEL}); //y sample negative slope
	t_line line1 = (t_line){100, 100, 150, 150, BLUE_PIXEL};
	t_line line2 = (t_line){150, 150, 100, 200, BLUE_PIXEL};
	t_line line3 = (t_line){100, 200, 50, 150, BLUE_PIXEL};
	t_line line4 = (t_line){50, 150, 100, 100, BLUE_PIXEL};
	render_line(&data->img, line1); 
	render_line(&data->img, line2);
	render_line(&data->img, line3); 
	render_line(&data->img, line4);

	t_line line5 = rotate_45dl(line1);
	t_line line6 = rotate_45dl(line2);
	t_line line7 = rotate_45dl(line3);
	t_line line8 = rotate_45dl(line4);
	render_line(&data->img, line5);
	render_line(&data->img, line6);
	render_line(&data->img, line7);
	render_line(&data->img, line8);
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	
	return (0);
}

int main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (MLX_ERROR);

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Minha primeira janela");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}

	//creating an image
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.line_len, &data->img.endian);

	//preparar hooks
	mlx_loop_hook(data->mlx_ptr, &render, data); //cada frame vai renderizar o mesmo pixel
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);

	mlx_loop(data->mlx_ptr);

	//exit loop if there's no window left
}
