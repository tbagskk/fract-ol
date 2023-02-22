#include "../fractol.h"

void	julia_valeur(int nb, void *param)
{
	t_caca		*caca;
	t_fractal	*f;

	caca = malloc(sizeof(t_caca));
	f = (t_fractal *)malloc(sizeof(t_fractal));
	caca = param;
	if (nb == 1)
	{
		caca->x_julia -= 0.1;
		caca->y_julia -= 0.1;
		julia(f, caca->mlx, caca->img, caca);
	}
	else if (nb == 2)
	{
		caca->x_julia += 0.1;
		caca->y_julia += 0.1;
		julia(f, caca->mlx, caca->img, caca);
	}


}

void	loop_hook(void *param)
{
	t_caca		*caca;
	t_fractal	*f;

	//caca = malloc(sizeof(t_caca));
	//f = (t_fractal *)malloc(sizeof(t_fractal));
	caca = param;
	if (mlx_is_key_down(caca->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(caca->mlx);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_G))
		julia_valeur(2, param);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_F))
		julia_valeur(1, param);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_LEFT_SHIFT))
	{
		caca->shift += 1;
		choose_fractal(param);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{	
	t_caca		*caca;
	t_fractal	*f;
	int			x;
	int			y;

	(void)xdelta;
	//caca = malloc(sizeof(t_caca));
	caca = param;
	//f = (t_fractal *)malloc(sizeof(t_fractal));
	if (ydelta > 0)
	{
		caca->zoom = caca->zoom * 0.80;
		choose_fractal(param);
	}
	else if (ydelta < 0)
	{
		caca->zoom = caca->zoom / 0.80;
		choose_fractal(param);
	}
}
