
#ifndef FRACTOL_H
# define FRACTOL_H

#define WIDTH 700
#define HEIGHT 700

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
  
}               t_caca;

#endif