/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_load_points_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:43:20 by iusantos          #+#    #+#             */
/*   Updated: 2023/09/26 18:12:56 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(t_meta *meta, unsigned int line, unsigned int col)
{
	char *substr;

	if (ft_strchr(meta->map.data[line][col], ',') == NULL)
		set_default_color(meta, line, col);
	else
	{
		substr = ft_substr(
			ft_strchr(meta->map.data[line][col], ','), 1, 8);
		meta->pt_matrix.data[line][col].color = fdf_atox(substr);
		free(substr);
	}
}

void	set_default_color(t_meta *meta, unsigned int line, unsigned int col)
{
	meta->pt_matrix.data[line][col].color = DEFAULT_COLOR;
}

//hexadecimal string to int. hex digits may be upper or lowercase. radix may
//be 0x or 0X. 4 bytes max.
int	fdf_atox(const char *s)
{
	int	val;
	int	digit;

	s = s + 2;
	val = 0;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			digit = *s - 48;
		else if (*s >= 'a' && *s <= 'f')
			digit = *s - 87;
		else if (*s >= 'A' && *s <= 'F')
			digit = *s - 55;
		val = (val << 4) | (digit & 0xF);
		s++;
	}
	return (val);
}
