#include "MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int zoom = 4;
// fait les differents degradés de couleur avec 4 couleurs diff
int degrade(int i)
{
  if (i % 185 == 0 && i % 5 == 0)
    return (couleur1);
  else if (i % 3 == 0)
    return (couleur2);
  else if (i % 5 == 0)
    return (couleur3);
  else
    return (couleur4);
}


// dessine la fractal avec les couleurs
int		get_color(int iter)
{
  int couleur;
  t_caca *caca;

  if (iter == 250)
    return (0X002c90FF);
  else
  {
    couleur = degrade(iter);
    return(couleur);
  }
   // return (BLUE * iter / 50);
}

// algo pour mandelbrot trop grand, a decouper
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

void color_background(void *background, char c)
{

 int color; 
 
  if (c == 'r')
    color = 0xFF0000FF;
  else if (c == 'n')
    color = 0x000000FF;
  
  int i;
  int x;

  i = 0;
  x = 0;
  
  while (i < 800)
	{
		x = 0;
		while (x < 1200)
		{
      mlx_put_pixel(background, x, i, color);
			x++;
		}
		i++;
  }
}
void	shift_view(t_caca *caca, int key)
{
  
  caca = malloc(sizeof(t_caca));

  if (key == 0)
  {
     caca->zoom -= 1;

  }
}

void loop_hook(void *param)
{
  t_caca *caca;
  caca = malloc(sizeof(t_caca));
  t_fractal *f;
  f = (t_fractal*)malloc(sizeof(t_fractal));

  caca = param;
  if (mlx_is_key_down(caca->mlx, MLX_KEY_ESCAPE))
	  	mlx_close_window(caca->mlx);
  else if (mlx_is_key_down(caca->mlx, MLX_KEY_UP))
  {
    caca->zoom -= 3;
    caca->max_iter -= 100;

    mandelbrot(f, caca->mlx, caca->img, caca);
  }
  else if (mlx_is_key_down(caca->mlx, MLX_KEY_DOWN))
  {
    caca->zoom += 3;
    caca->max_iter += 100;

    mandelbrot(f, caca->mlx, caca->img, caca);
  }
  else if (mlx_is_key_down(caca->mlx, MLX_KEY_K))
  {
    caca->x += 0.05;
    mandelbrot(f, caca->mlx, caca->img, caca);
  }
  else if (mlx_is_key_down(caca->mlx, MLX_KEY_L))
  {
    caca->x -= 0.05;
    mandelbrot(f, caca->mlx, caca->img, caca);
  } 	
}

void scrool_hook(void *param)
{
  
}

int32_t		main(void)
{
  mlx_image_t* background;
  mlx_image_t* img;
  t_caca *caca;
  t_fractal *f;
  f = (t_fractal*)malloc(sizeof(t_fractal));
  
  caca = malloc(sizeof(t_caca));
  caca->zoom = 4;
  caca->max_iter = 250;
  caca->x = 0;
  caca->y = 0;


  caca->mlx = mlx_init(1200, 800, "fracol", true);
  caca->img = mlx_new_image(caca->mlx, WIDTH, HEIGHT);
  background = mlx_new_image(caca->mlx, 1200, 800);
  memset(background->pixels, 255 , background->width * background->height * sizeof(int));
  mlx_image_to_window(caca->mlx, background, 0, 0);
  mlx_image_to_window(caca->mlx, caca->img,50, 50);
  color_background(background, 'r');
  mandelbrot(f, caca->mlx, caca->img, caca);

  mlx_loop_hook(caca->mlx, &loop_hook, caca);
  mlx_scroll_hook(caca->mlx, &scrool_hook, caca);
  mlx_loop(caca->mlx);
  return (0);
}