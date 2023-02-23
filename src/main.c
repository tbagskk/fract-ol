/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 07:51:13 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 13:03:20 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <unistd.h>

void	init_values(t_fract *fract)
{
	fract->shift = 1;
	fract->zoom = 10;
	fract->max_iter = 10;
	fract->x = 0;
	fract->y = 0;
	fract->x_julia = 0.8;
	fract->y_julia = 0.285;
	fract->width = 1200;
	fract->height = 800;
	fract->width2 = 1200;
	fract->height2 = 800;
	fract->color_r = 10;
	fract->color_g = 20;
	fract->color_b = 30;
	fract->color_shift = 1;
}

void	launch(t_fractal *f, t_fract *fract)
{
	if (fract->fract == 2)
		julia(f, fract->mlx, fract->img, fract);
	else if (fract->fract == 1)
	{
		fract->shift = 2;
		mandelbrot(f, fract->mlx, fract->img, fract);
	}	
}

void	loop(t_fractal *f, t_fract *fract)
{
	mlx_image_t	*background;

	fract->mlx = mlx_init(1200, 800, "fractol", true);
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	background = mlx_new_image(fract->mlx, 1200, 800);
	memset(background->pixels, 255, background->width
		* background->height * sizeof(int));
	mlx_image_to_window(fract->mlx, background, 0, 0);
	mlx_image_to_window(fract->mlx, fract->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_fract		*fract;
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	fract = malloc(sizeof(t_fract));
	init_values(fract);
	if ((verif_ac(ac, av[1], f, fract)))
	{
		loop(f, fract);
		launch(f, fract);
		textures_fract(f, fract);
		textures_param(f, fract);
		mlx_loop_hook(fract->mlx, &loop_hook, fract);
		mlx_scroll_hook(fract->mlx, &my_scrollhook, fract);
		mlx_loop(fract->mlx);
	}
	free(fract);
	free(f);
	return (0);
}
