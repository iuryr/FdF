#include "fdf.h"
#include <mlx.h>

int	render2(t_meta *meta)
{
	if (meta->win_ptr == NULL)
		return (-1);
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img,
		0, 0);
	return (0);
}

int main(void)
{
	t_meta meta;

	t_point	p1 = (t_point){10,10,0,10,10,0}; //horizontal IF
	t_point	p2 = (t_point){110,10,0,110,10,0};

	t_point	p3 = (t_point){300,10,0,300,10,0}; //horizontal FI
	t_point	p4 = (t_point){200,10,0,200,10,0};

	t_point	p5 = (t_point){50,30,0,50,30,0}; //vertical IF
	t_point	p6 = (t_point){50,130,0,50,130,0};

	t_point	p7 = (t_point){250,130,0,250,130,0}; //vertical FI
	t_point	p8 = (t_point){250,30,0,250,30,0};

	t_point	p9 = (t_point){30,160,0,30,160,0}; //diagonal positiva IF
	t_point	p10 = (t_point){70,200,0,70,200,0};

	t_point	p11 = (t_point){260,200,0,260,200,0}; //diagonal positiva FI
	t_point	p12 = (t_point){220,160,0,220,160,0};

	t_point	p13 = (t_point){30,270,0,30,270,0}; //diagonal negativa IF
	t_point	p14 = (t_point){80,220,0,80,220,0};

	t_point	p15 = (t_point){270,220,0,270,220,0}; //diagonal negativa FI
	t_point	p16 = (t_point){220,270,0,270,220,0};

	t_point	p17 = (t_point){30,300,0,30,300,0}; //abs(slope) < 1 IF
	t_point	p18 = (t_point){100,330,0,100,330,0};

	t_point	p19 = (t_point){310,330,0,310,330,0}; //abs(slope) <1 FI
	t_point	p20 = (t_point){240,300,0,240,300,0};

	t_point	p21 = (t_point){30,350,0,30,350,0}; //abs(slope) > 1 IF
	t_point	p22 = (t_point){50,450,0,50,450,0};

	t_point	p23 = (t_point){280,450,0,280,450,0}; //abs(slope) >1 FI
	t_point	p24 = (t_point){250,350,0,250,350,0};

	system_init(&meta);
	img_init(&meta);
	render_bg(meta.img, WHITE_PIXEL);

	draw_line(p1, p2, RED_PIXEL, meta.img);
	draw_line(p3, p4, RED_PIXEL, meta.img);
	draw_line(p5, p6, RED_PIXEL, meta.img);
	draw_line(p7, p8, RED_PIXEL, meta.img);
	draw_line(p9, p10, RED_PIXEL, meta.img);
	draw_line(p11, p12, RED_PIXEL, meta.img);
	draw_line(p13, p14, RED_PIXEL, meta.img);
	draw_line(p15, p16, RED_PIXEL, meta.img);
	draw_line(p17, p18, RED_PIXEL, meta.img);
	draw_line(p19, p20, RED_PIXEL, meta.img);
	draw_line(p21, p22, RED_PIXEL, meta.img);
	draw_line(p23, p24, RED_PIXEL, meta.img);

	mlx_hook(meta.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &meta);
	mlx_loop_hook(meta.mlx_ptr, &render2, &meta);
	mlx_loop(meta.mlx_ptr);
}
