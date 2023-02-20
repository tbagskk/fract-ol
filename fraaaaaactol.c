#include "MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>


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
int		mandelbrot(t_fractal f, mlx_t *mlx, void *img)
{
  int	iter;
  int	color;
  int	x;
  int	y;

  x = -1;
  y = -1;
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
      while (f.z.r * f.z.r + f.z.i * f.z.i < 4 && ++iter < 250)
      {
        f.z = (t_complex){f.z.r * f.z.r - f.z.i * f.z.i + f.c.r,
                          2 * f.z.r * f.z.i + f.c.i};
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

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		puts("Hello ");
  
		 
}
int		main(void)
{
  mlx_image_t* background;
  mlx_image_t* img;
  mlx_t* mlx;
  t_fractal	f;


  mlx = mlx_init(1200, 800, "fracol", true);

  img = mlx_new_image(mlx, WIDTH, HEIGHT);
  background = mlx_new_image(mlx, 1200, 800);
  memset(background->pixels, 255 , background->width * background->height * sizeof(int));
  mlx_image_to_window(mlx, background, 0, 0);
  mlx_image_to_window(mlx, img, 50, 50);
  color_background(background, 'r');
	mlx_key_hook(mlx, &key_hook, NULL);
  

  mandelbrot(f, mlx, img);
  mlx_loop(mlx);
  return (0);
}