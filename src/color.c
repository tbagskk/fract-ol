/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:03:43 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 08:03:53 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void action_color(t_fractal *f, t_caca *caca)
{
	caca->color_shift += 1;
	choose_fractal(caca->shift, caca, f);
}

int	get_color(int iter, t_caca *caca)
{
	int		r;
	int		g;
	int		b;

	if (iter == caca->max_iter)
		return (WHITE);
	r = (iter * caca->color_r) % 256;
	g = (iter * caca->color_g) % 256;
	b = (iter * caca->color_b) % 256;
	return (r << 16 | g << 8 | b);
}

int	get_color2(int iter, t_caca *caca)
{
	int		r;
	int		g;
	int		b;

	if (iter == caca->max_iter)
		return (PINK);
	r = (iter * 30) % 256;
	g = (iter * 30) % 256;
	b = (iter * 30) % 256;
	return (r << 16 | g << 8 | b);
}

int	get_color3(int iter, t_caca *caca)
{
	int		r;
	int		g;
	int		b;

	if (iter == caca->max_iter)
		return (GREEN);
	r = (iter * 30) % 256;
	g = (iter * 20) % 256;
	b = (iter * 30) % 256;
	return (r << 16 | g << 8 | b);
}

int choose_color(int iter, t_caca *caca)
{
	int a;
	
	a = 0;
	if (caca->color_shift > 3)
		caca->color_shift = 1;
	if (caca->color_shift == 1)
		a = get_color(iter, caca);
	else if (caca->color_shift == 2)
		a = get_color2(iter, caca);
	else if (caca->color_shift == 3)
		a = get_color3(iter, caca);
	
	return (a);

}