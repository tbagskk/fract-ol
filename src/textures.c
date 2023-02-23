/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:43 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 16:05:02 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_textures(t_fractal *f, t_fract *fract)
{
	mlx_texture_t	*texture_m;
	mlx_image_t		*img_m;

	texture_m = mlx_load_png("./textures/mandelbrot.png");
	img_m = mlx_texture_to_image(fract->mlx, texture_m);
	mlx_image_to_window(fract->mlx, img_m, 50, 700);
	mlx_delete_texture(texture_m);
}

void	textures_fract(t_fractal *f, t_fract *fract)
{
	mlx_texture_t	*texture_j;
	mlx_image_t		*img_julia;
	mlx_texture_t	*texture_m;
	mlx_image_t		*img_m;

	texture_j = mlx_load_png("./textures/julia.png");
	img_julia = mlx_texture_to_image(fract->mlx, texture_j);
	if (fract->shift == 1)
	{
		mlx_delete_image(fract->mlx, img_m);
		mlx_image_to_window(fract->mlx, img_julia, 50, 700);
	}
	else if (fract->shift == 2)
	{
		mlx_delete_image(fract->mlx, img_julia);
		init_textures(f, fract);
	}
	mlx_delete_texture(texture_j);
}

void	textures_param(t_fractal *f, t_fract *fract)
{
	mlx_texture_t	*texture_p;
	mlx_image_t		*img_p;

	texture_p = mlx_load_png("./textures/parametres.png");
	img_p = mlx_texture_to_image(fract->mlx, texture_p);
	mlx_image_to_window(fract->mlx, img_p, 50, 50);
	mlx_delete_texture(texture_p);
}
