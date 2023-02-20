#include "mlx.h"
#include <stdlib.h>

#define WIDTH 600
#define HEIGHT 600

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

int		get_color(int iter)
{
  if (iter == 0)
    return (0x000000);
  else
    return (0xFFFFFF / iter);
}

int		draw_fractal(t_fractal f, void *mlx, void *win)
{
  int	iter;
  int	color;
  int	x;
  int	y;

  x = -1;
  while (++x < WIDTH)
  {
    y = -1;
    while (++y < HEIGHT)
    {
      f.z.r = 0;
      f.z.i = 0;
      f.c.r = (x - WIDTH / 2.0) * 4.0 / WIDTH;
      f.c.i = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
      iter = -1;
      while (f.z.r * f.z.r + f.z.i * f.z.i < 4 && ++iter < 255)
      {
        f.z = (t_complex){f.z.r * f.z.r - f.z.i * f.z.i + f.c.r,
                          2 * f.z.r * f.z.i + f.c.i};
      }
      color = get_color(iter);
      mlx_pixel_put(mlx, win, x, y, color);
    }
  }
  return (0);
}

int		main(void)
{
  void	*mlx;
  void	*win;
  t_fractal	f;

  mlx = mlx_init();
  win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mandelbrot Set");
  draw_fractal(f, mlx, win);
  mlx_loop(mlx);
  return (0);
}
