#include "../fractol.h"

int		mandelbrot(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca)
{
  int	iter;
  int	color;
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (++x < WIDTH)
  {
    y = 0;
    while (++y < HEIGHT)
    {
      f->z.r = caca->x;
      f->z.i = caca->y;
      f->c.r = (x - WIDTH / 2.0) * caca->zoom / WIDTH;
      f->c.i = (y - HEIGHT / 2.0) * caca->zoom / WIDTH;
      iter = -1;
      while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && ++iter < caca->max_iter)
      {
        f->z = (t_complex){f->z.r * f->z.r - f->z.i * f->z.i + f->c.r,
                          2 * f->z.r * f->z.i + f->c.i};
      }
      color = get_color(iter);
      mlx_put_pixel(img, x, y, color);
	   
    }
  } 
  return (0);
}

int julia(t_fractal *f, mlx_t *mlx, void *img, t_caca *caca)
{
  int iter;
  int color;
  int x;
  int y;

  x = 0;
  caca->c.i = caca->x_julia;
  caca->c.r = caca->y_julia;
  
  while (++x < WIDTH)
  {
    y = 0;
    while (++y < HEIGHT)
    {
      f->z.r = (x - WIDTH / 2.0) * caca->zoom / WIDTH;
      f->z.i = (y - HEIGHT / 2.0) * caca->zoom / WIDTH;
      iter = -1;
      while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && ++iter <= 250)
      {
        t_complex old_z = f->z;
        f->z.r = old_z.r * old_z.r - old_z.i * old_z.i + caca->c.r;
        f->z.i = 2 * old_z.r * old_z.i + caca->c.i;
      }
      color = get_color(iter);
      mlx_put_pixel(img, x, y, color);
    }
  }
  return (0);
}