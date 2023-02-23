/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:03:43 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 15:49:40 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	action_color(t_fractal *f, t_fract *fract)
{
	fract->color_shift += 1;
	choose_fractal(fract->shift, fract, f);
}

int	get_color(int iter, t_fract *fract)
{
	int		r;
	int		g;
	int		b;

	if (iter == fract->max_iter)
		return (WHITE);
	r = (iter * fract->color_r) % 256;
	g = (iter * fract->color_g) % 256;
	b = (iter * fract->color_b) % 256;
	return (r << 16 | g << 8 | b);
}

int	get_color2(int iter, t_fract *fract)
{
	int		r;
	int		g;
	int		b;

	if (iter == fract->max_iter)
		return (PINK);
	r = (iter * 30) % 256;
	g = (iter * 30) % 256;
	b = (iter * 30) % 256;
	return (r << 16 | g << 8 | b);
}

int	get_color3(int iter, t_fract *fract)
{
	int		r;
	int		g;
	int		b;

	if (iter == fract->max_iter)
		return (GREEN);
	r = (iter * 30) % 256;
	g = (iter * 20) % 256;
	b = (iter * 30) % 256;
	return (r << 16 | g << 8 | b);
}

int	choose_color(int iter, t_fract *fract)
{
	int	a;

	a = 0;
	if (fract->color_shift > 3)
		fract->color_shift = 1;
	if (fract->color_shift == 1)
		a = get_color(iter, fract);
	else if (fract->color_shift == 2)
		a = get_color2(iter, fract);
	else if (fract->color_shift == 3)
		a = get_color3(iter, fract);
	return (a);
}
