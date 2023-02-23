/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:03:04 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 08:03:25 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_valeur(int nb, t_caca *caca, t_fractal *f)
{
	if (nb == 1)
	{
		caca->x_julia -= 0.1;
		caca->y_julia -= 0.1;
		choose_fractal(caca->shift, caca, f);
	}
	else if (nb == 2)
	{
		caca->x_julia += 0.1;
		caca->y_julia += 0.1;
		choose_fractal(caca->shift, caca, f);
	}
}

void	loop_hook(void *param)
{
	t_caca		*caca;
	t_fractal	*f;

	caca = param;
	if (mlx_is_key_down(caca->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(caca->mlx);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_RIGHT))
		julia_valeur(2, caca, f);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_LEFT))
		julia_valeur(1, caca, f);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_LEFT_SHIFT))
		action_color(f, caca);
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_1))
	{
		caca->shift = 1;
		choose_fractal(caca->shift, caca, f);
	}
	else if (mlx_is_key_down(caca->mlx, MLX_KEY_2))
	{
		caca->shift = 2;
		choose_fractal(caca->shift, caca, f);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{	
	t_caca		*caca;
	t_fractal	*f;

	(void)xdelta;
	caca = param;
	if (ydelta > 0)
	{
		caca->zoom = caca->zoom * 0.80;
		caca->max_iter += 2;
		choose_fractal(caca->shift, caca, f);
	}
	else if (ydelta < 0)
	{
		caca->zoom = caca->zoom / 0.80;
		caca->max_iter -= 2;
		choose_fractal(caca->shift, caca, f);
	}
}
