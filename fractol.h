/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:28:21 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 15:40:38 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include	"MLX42/include/MLX42/MLX42.h"
# include	<stdlib.h>
# include	<memory.h>
# include	<stdbool.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<math.h>

# define WIDTH 	1200
# define HEIGHT	800

# define WHITE	0xFFFFFFFF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define PINK	0xFF00F4FF
# define BLACK	0x000000FF

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_fractal
{
	t_complex		c;
	t_complex		z;
	int				iter;
}				t_fractal;

typedef struct s_caca
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_complex	c;
	t_complex	old_z;
	double		zoom;
	double		x;
	double		y;
	double		x_julia;
	double		y_julia;
	int			max_iter;
	int			width;
	int			height;
	int			width2;
	int			height2;
	int			shift;
	int			color_r;
	int			color_g;
	int			color_b;
	int			iter;
	int			color;
	int			x2;
	int			y2;
	int			fract;
	int			color_shift;
}				t_caca;

void	mandelbrot(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca);
int		get_color(int iter, t_caca *caca);
void	julia_valeur(int nb, t_caca *caca, t_fractal *f);
void	choose_fractal(int nb, t_caca *caca, t_fractal *f);
void	loop_hook(void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);
void	julia(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca);
void	calcul(t_fractal *f, t_caca *caca);
int		ft_strcmp(char *s1, char *s2);
int		verif_fractal(char *str, t_fractal *f, t_caca *caca);
int		verif_ac(int ac, char *str, t_fractal *f, t_caca *caca);
void	textures_fract(t_fractal *f, t_caca *caca);
int		choose_color(int iter, t_caca *caca);
void	action_color(t_fractal *f, t_caca *caca);
void	textures_param(t_fractal *f, t_caca *caca);
void	init_textures(t_fractal *f, t_caca *caca);

#endif
