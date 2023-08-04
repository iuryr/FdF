#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h> //macros com definição de teclas
#include <X11/X.h> //macros com definição de events e masks

#define WINDOW_WIDTH 800
#define	WINDOW_HEIGHT 800

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define	GREEN_PIXEL 0x00FF00
#define	WHITE_PIXEL 0xFFFFFF

//t_line data type
typedef struct s_line
{
	int x_s;
	int y_s;
	int x_f;
	int y_f;
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


int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);

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


int	render_line(t_img *img, t_line line)
{
	int dx = line.x_f - line.x_s;
	int dy = line.y_f - line.y_s;
	int i;
	int j;
	int p;

	p = 2 * dy - dx;

	i = line.x_s;
	j = line.y_s;
	while (i < line.x_f)
	{
		img_pix_put(img, i, j, line.color);
		i++;

		if (p < 0)
			p = p + 2 * dy;
		else
		{
			p = p + 2 * dy + 2 * dx;
			j++;
		}
	}
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
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	render_line(&data->img, (t_line){0, 0, 400, 10, RED_PIXEL});

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
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
}
