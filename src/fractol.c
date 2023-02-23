/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:08:15 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 09:11:44 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca)
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
			f->z.r = caca->x;
			f->z.i = caca->y;
			f->c.r = (x - WIDTH / 2.0) * caca->zoom / WIDTH;
			f->c.i = (y - HEIGHT / 2.0) * caca->zoom / WIDTH;
			caca->iter = -1;
			while (f->z.r * f->z.r + f->z.i * f->z.i
				< 4 && ++caca->iter < caca->max_iter)
			{
				f->z = (t_complex){f->z.r * f->z.r - f->z.i * f->z.i + f->c.r,
					2 * f->z.r * f->z.i + f->c.i};
			}
			caca->color = choose_color(caca->iter, caca);
			mlx_put_pixel(img, x, y, caca->color);
		}
	}	
}

void	calcul(t_fractal *f, t_caca *caca)
{
	t_complex	old_z;

	old_z = f->z;
	f->z.r = old_z.r * old_z.r - old_z.i * old_z.i + caca->c.r;
	f->z.i = 2 * old_z.r * old_z.i + caca->c.i;
}

void	julia(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca)
{
	t_complex	old_z;
	int			x;
	int			y;

	x = 0;
	caca->c.i = caca->x_julia;
	caca->c.r = caca->y_julia;
	while (++x < WIDTH)
	{
		y = 0;
		while (++y < HEIGHT)
		{
			f->z.r = (x - WIDTH / 2.0) * caca->zoom / WIDTH;
			f->z.i = (y - HEIGHT / 2.0) * caca->zoom / WIDTH;
			caca->iter = -1;
			while (f->z.r * f->z.r + f->z.i * f->z.i
				< 4 && ++caca->iter <= caca->max_iter)
				calcul(f, caca);
			caca->color =  choose_color(caca->iter, caca);
			mlx_put_pixel(img, x, y, caca->color);
		}
	}
}