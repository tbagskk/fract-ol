#include "../fractol.h"

int	get_color(int iter, t_caca *caca)
{
	int		r;
	int		g;
	int		b;

	if (iter == caca->max_iter)
		return (WHITE);
	r = (iter * caca->color_r) % 256;
	g = (iter * caca->color_g) % 256;
	b = (iter * caca->color_b) % 256;
	return (r << 16 | g << 8 | b);
}

