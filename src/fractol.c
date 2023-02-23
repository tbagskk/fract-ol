/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:08:15 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:41 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fractal *f, mlx_t *mlx, void *img, t_fract *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			f->z.r = fract->x;
			f->z.i = fract->y;
			f->c.r = (x - WIDTH / 2.0) * fract->zoom / WIDTH;
			f->c.i = (y - HEIGHT / 2.0) * fract->zoom / WIDTH;
			fract->iter = -1;
			while (f->z.r * f->z.r + f->z.i * f->z.i
				< 4 && ++fract->iter < fract->max_iter)
			{
				f->z = (t_complex){f->z.r * f->z.r - f->z.i * f->z.i + f->c.r,
					2 * f->z.r * f->z.i + f->c.i};
			}
			fract->color = choose_color(fract->iter, fract);
			mlx_put_pixel(img, x, y, fract->color);
		}
	}	
}

void	calcul(t_fractal *f, t_fract *fract)
{
	t_complex	old_z;

	old_z = f->z;
	f->z.r = old_z.r * old_z.r - old_z.i * old_z.i + fract->c.r;
	f->z.i = 2 * old_z.r * old_z.i + fract->c.i;
}

void	julia(t_fractal *f, mlx_t *mlx, void *img, t_fract *fract)
{
	t_complex	old_z;
	int			x;
	int			y;

	x = 0;
	fract->c.i = fract->x_julia;
	fract->c.r = fract->y_julia;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			f->z.r = (x - WIDTH / 2.0) * fract->zoom / WIDTH;
			f->z.i = (y - HEIGHT / 2.0) * fract->zoom / WIDTH;
			fract->iter = -1;
			while (f->z.r * f->z.r + f->z.i * f->z.i
				< 4 && ++fract->iter <= fract->max_iter)
				calcul(f, fract);
			fract->color = choose_color(fract->iter, fract);
			mlx_put_pixel(img, x, y, fract->color);
		}
	}
}
