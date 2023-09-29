/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_keys_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:22:43 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/28 14:03:40 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	handle_keypress(int keysym, t_meta *meta)
{
	if (keysym == XK_Escape)
	{
		on_close(meta);
	}
	return (0);
}
