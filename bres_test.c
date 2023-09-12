#include "fdf.h"
#include <mlx.h>

int	render2(t_meta *meta)
{
	mlx_put_image_to_window(meta->mlx_ptr, meta->win_ptr, meta->img->mlx_img, 0, 0);
	return (0);
}

void bres_line(t_point start, t_point end, int color, t_img *img)
{
	t_draw_info info;

	init_draw_info(&info, start, end, color);
	if (ft_abs(info.dy) <= ft_abs(info.dx))
	{
		if (info.dx < 0)
			draw_line_low(end, start, info);
		else
			draw_line_low(start, end, info);
	}
	else
	{
		if (info.dy < 0)
			draw_line_high(end, start, info);
		else
			draw_line_high(start, end, info);
	}
}

void	draw_line_low(t_point start, t_point end, t_draw_info info)
{
	
}

int main(void)
{
	t_meta meta;

	t_point	p1 = (t_point){10,10,0,10,10,0}; //horizontal IF
	t_point	p2 = (t_point){30,10,0,30,10,0};
	t_point	p3 = (t_point){80,10,0,80,10,0}; //horizontal FI
	t_point	p4 = (t_point){40,10,0,40,10,0};
	t_point	p5 = (t_point){70,20,0,70,20,0}; //vertical IF
	t_point	p6 = (t_point){70,50,0,70,50,0};
	t_point	p7 = (t_point){80,100,0,80,100,0}; //vertical FI
	t_point	p8 = (t_point){80,70,0,80,70,0};
	t_point	p9 = (t_point){100,150,0,100,150,0}; //diagonal positiva IF
	t_point	p10 = (t_point){200,250,0,200,250,0};
	t_point	p11 = (t_point){250,100,0,250,100,0}; //diagonal positiva FI
	t_point	p12 = (t_point){200,50,0,200,50,0};
	t_point	p13 = (t_point){300,400,0,300,400,0}; //diagonal negativa IF
	t_point	p14 = (t_point){350,350,0,350,350,0};
	t_point	p15 = (t_point){500,600,0,500,600,0}; //diagonal negativa FI
	t_point	p16 = (t_point){450,650,0,450,650,0};
	t_point	p17 = (t_point){700,700,0,700,700,0}; //abs(slope) < 1 IF
	t_point	p18 = (t_point){800,760,0,800,760,0};
	t_point	p19 = (t_point){500,400,0,500,400,0}; //abs(slope) <1 FI
	t_point	p20 = (t_point){300,300,0,300,300,0};
	t_point	p21 = (t_point){700,100,0,700,100,0}; //abs(slope) > 1 IF
	t_point	p22 = (t_point){800,400,0,800,400,0};
	t_point	p23 = (t_point){900,500,0,900,500,0}; //abs(slope) >1 FI
	t_point	p24 = (t_point){600,100,0,600,100,0};

	system_init(&meta);
	img_init(&meta);
	render_bg(meta.img, WHITE_PIXEL);
	bres_line(p1, p2, RED_PIXEL, meta.img);
	bres_line(p3, p4, RED_PIXEL, meta.img);
	bres_line(p5, p6, RED_PIXEL, meta.img);
	bres_line(p7, p8, RED_PIXEL, meta.img);
	bres_line(p9, p10, RED_PIXEL, meta.img);
	bres_line(p11, p12, RED_PIXEL, meta.img);
	bres_line(p13, p14, RED_PIXEL, meta.img);
	bres_line(p15, p16, RED_PIXEL, meta.img);
	bres_line(p17, p18, RED_PIXEL, meta.img);
	bres_line(p19, p20, RED_PIXEL, meta.img);
	bres_line(p21, p22, RED_PIXEL, meta.img);
	bres_line(p23, p24, RED_PIXEL, meta.img);

	mlx_loop_hook(meta.mlx_ptr, &render2, &meta);
	mlx_loop(meta.mlx_ptr);



}
