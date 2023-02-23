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

void	init_values(t_caca *caca)
{
	caca->shift = 1;
	caca->zoom = 10;
	caca->max_iter = 10;
	caca->x = 0;
	caca->y = 0;
	caca->x_julia = 0.8;
	caca->y_julia = 0.285;
	caca->width = 1200;
	caca->height = 800;
	caca->width2 = 1200;
	caca->height2 = 800;
	caca->color_r = 10;
	caca->color_g = 20;
	caca->color_b = 30;
	caca->color_shift = 1;
}

void	launch(t_fractal *f, t_caca *caca)
{
	if (caca->fract == 2)
		julia(f, caca->mlx, caca->img, caca);
	else if (caca->fract == 1)
	{
		caca->shift = 2;
		mandelbrot(f, caca->mlx, caca->img, caca);
	}	
}

void	loop(t_fractal *f, t_caca *caca)
{
	mlx_image_t	*background;

	caca->mlx = mlx_init(1200, 800, "fractol", true);
	caca->img = mlx_new_image(caca->mlx, WIDTH, HEIGHT);
	background = mlx_new_image(caca->mlx, 1200, 800);
	memset(background->pixels, 255, background->width
		* background->height * sizeof(int));
	mlx_image_to_window(caca->mlx, background, 0, 0);
	mlx_image_to_window(caca->mlx, caca->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_caca		*caca;
	t_fractal	*f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	caca = malloc(sizeof(t_caca));
	init_values(caca);
	if ((verif_ac(ac, av[1], f, caca)))
	{
		loop(f, caca);
		launch(f, caca);
		textures_fract(f, caca);
		textures_param(f, caca);
		mlx_loop_hook(caca->mlx, &loop_hook, caca);
		mlx_scroll_hook(caca->mlx, &my_scrollhook, caca);
		mlx_loop(caca->mlx);
	}
	free(caca);
	free(f);
	system("leaks a.out");
	return (0);
}
