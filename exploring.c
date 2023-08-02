#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h> //macros com definição de teclas
#include <X11/X.h> //macros com definição de events e masks

#define WINDOW_WIDTH 800
#define	WINDOW_HEIGHT 600
#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
}	t_data;

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

int	render(t_data *data)
{
	if (data->win_ptr != NULL) //importante checar se a janela ainda existe
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);

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
