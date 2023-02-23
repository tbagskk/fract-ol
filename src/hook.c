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

void	julia_valeur(int nb, t_fract *fract, t_fractal *f)
{
	if (nb == 1)
	{
		fract->x_julia -= 0.1;
		fract->y_julia -= 0.1;
		choose_fractal(fract->shift, fract, f);
	}
	else if (nb == 2)
	{
		fract->x_julia += 0.1;
		fract->y_julia += 0.1;
		choose_fractal(fract->shift, fract, f);
	}
}

void	loop_hook(void *param)
{
	t_fract		*fract;
	t_fractal	*f;

	fract = param;
	if (mlx_is_key_down(fract->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fract->mlx);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_RIGHT))
		julia_valeur(2, fract, f);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT))
		julia_valeur(1, fract, f);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_LEFT_SHIFT))
		action_color(f, fract);
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_1))
	{
		fract->shift = 1;
		choose_fractal(fract->shift, fract, f);
	}
	else if (mlx_is_key_down(fract->mlx, MLX_KEY_2))
	{
		fract->shift = 2;
		choose_fractal(fract->shift, fract, f);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{	
	t_fract		*fract;
	t_fractal	*f;

	(void)xdelta;
	fract = param;
	if (ydelta > 0)
	{
		fract->zoom = fract->zoom * 0.80;
		fract->max_iter += 2;
		choose_fractal(fract->shift, fract, f);
	}
	else if (ydelta < 0)
	{
		fract->zoom = fract->zoom / 0.80;
		fract->max_iter -= 2;
		choose_fractal(fract->shift, fract, f);
	}
}
