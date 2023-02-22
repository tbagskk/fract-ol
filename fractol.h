
#ifndef FRACTOL_H
# define FRACTOL_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 1200
#define HEIGHT 800

#define RED 0xFF0000FF
#define GREEN 0x00FF00FF
#define BLUE 0x0000FFFF
#define PINK 0xFF00F4FF
#define BLACK 0x000000FF

#define couleur1 0xFF0000FF
#define couleur2 0xFF4949FF
#define couleur3 0xFF7e7eFF
#define couleur4 0xFea0a0FF
#define couleur5 0xFFbFbFFF

typedef struct	s_complex
{
  double		r;
  double		i;
}				t_complex;

typedef struct	s_fractal
{
  t_complex		c;
  t_complex		z;
  int			iter;
}				t_fractal;

typedef struct s_caca
{
  double         zoom;
  int         max_iter;
  mlx_t*      mlx;
  mlx_image_t* img;
  double        x;
  double        y;
  double        x_julia;
  double        y_julia;
  t_complex		c;
  
}               t_caca;

int		mandelbrot(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca);
int get_color(int iter);
int julia(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca);
#endif