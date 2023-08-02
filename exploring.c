#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h> //macros com definição de teclas

#define WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300
#define MLX_ERROR 1

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
}	t_data;

int	handle_no_event(void *data)
{
	/* inutil por ora*/
	return (0);
}

int handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
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
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_key_hook(data->win_ptr, &handle_input, data);

	mlx_loop(data->mlx_ptr);

	//exit loop if there's no window left
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);

}
