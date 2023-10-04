/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_hooks_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:33:38 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/04 19:12:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	init_hooks(t_meta *meta)
{
	mlx_loop_hook(meta->mlx_ptr, &render, meta);
	mlx_hook(meta->win_ptr, KeyPress, KeyPressMask, &handle_keypress, meta);
	mlx_hook(meta->win_ptr, KeyRelease, KeyReleaseMask, &handle_keypress2,
		meta);
	mlx_hook(meta->win_ptr, DestroyNotify, NoEventMask, &on_close, meta);
	return (0);
}
