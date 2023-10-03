#include "fdf_bonus.h"

int	init_hooks(t_meta *meta)
{
	mlx_loop_hook(meta->mlx_ptr, &render, meta);
	mlx_hook(meta->win_ptr, KeyPress, KeyPressMask, &handle_keypress, meta);
	mlx_hook(meta->win_ptr, DestroyNotify, NoEventMask, &on_close, meta);
	return (0);
}
