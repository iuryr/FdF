#include <mlx.h>
#include <stdio.h>

int main(void)
{
	void	*mlx_ptr;
	void	*wnd_ptr;
	int		key_event;
	int	(*func_ptr)(void *, void *);

	func_ptr = &mlx_destroy_window;
	
	mlx_ptr = mlx_init();
	wnd_ptr = mlx_new_window(mlx_ptr, 800, 600, "Minha primeira janela");
	mlx_loop(mlx_ptr);
	mlx_key_hook(wnd_ptr, (*func_ptr)(mlx_ptr, wnd_ptr), 0xff1b);
}
