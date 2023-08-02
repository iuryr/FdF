#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h> //macros com definição de teclas
#include <X11/X.h> //macros com definição de events e masks

#define WINDOW_WIDTH 800
#define	WINDOW_HEIGHT 600

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define	GREEN_PIXEL 0xFF00
#define	WHITE_PIXEL 0xFFFFFF

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
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

int render_rect(t_data *data, t_rect rect)
{
	int i;
	int j;

	if (data->win_ptr == NULL)
		return (1);

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_bg(t_data *data, int color)
{
	int i;
	int j;

	if (data->win_ptr == NULL)
		return ;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data-> mlx_ptr, data->win_ptr, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{
	render_bg(data, WHITE_PIXEL);
	render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	
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
