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
		meta->pt_matrix.data[line][col].color = ft_hextoi(substr);
		free(substr);
	}
}

void	set_default_color(t_meta *meta, unsigned int line, unsigned int col)
{
	meta->pt_matrix.data[line][col].color = DEFAULT_COLOR;
}
