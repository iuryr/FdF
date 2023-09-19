/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:22:43 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/19 15:28:46 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_meta *meta)
{
	unsigned int	i;

	i = 0;
	if (keysym == XK_Escape)
	{
		free_matrix_data(meta);
		free_map_data(meta);
		cleanup_graph_resources(meta);
		exit(0);
	}
	return (0);
}
