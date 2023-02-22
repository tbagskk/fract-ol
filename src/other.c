#include "../fractol.h"

void	choose_fractal(int nb, t_caca *caca, t_fractal *f)
{	
	f = (t_fractal *)malloc(sizeof(t_fractal));

	if (nb == 2)
		mandelbrot(f, caca->mlx, caca->img, caca);
	else if(nb == 1)
		julia(f, caca->mlx, caca->img, caca);
	free(f);
}