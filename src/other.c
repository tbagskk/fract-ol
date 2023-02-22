#include "../fractol.h"

void	choose_fractal(void *param)
{	
	t_caca		*caca;
	t_fractal	*f;

	caca = malloc(sizeof(t_caca));
	f = (t_fractal *)malloc(sizeof(t_fractal));
	caca = param;
	if (caca->shift % 2 == 0)
		mandelbrot(f, caca->mlx, caca->img, caca);
	else
		julia(f, caca->mlx, caca->img, caca);
}