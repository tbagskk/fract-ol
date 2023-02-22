
#include "../fractol.h"

void init_values(t_caca *caca)
{
  caca->shift = 1;
  caca->zoom = 10;
  caca->max_iter = 10;
  caca->x = 0;
  caca->y = 0;
  caca->x_julia = 0.8;
  caca->y_julia = 0.285; 
  caca->width = 1200;
  caca->height = 800;
  caca->width2 = 1200;
  caca->height2 = 800;
  caca->color_r = 10;
  caca->color_g = 20;
  caca->color_b = 30;
}

int	main(void)
{
  mlx_image_t* background;
  t_caca *caca;
  t_fractal *f;
  
  f = (t_fractal*)malloc(sizeof(t_fractal));
  caca = malloc(sizeof(t_caca));
  init_values(caca);
  caca->mlx = mlx_init(1200, 800, "fractol", true);
  caca->img = mlx_new_image(caca->mlx, WIDTH, HEIGHT);
  background = mlx_new_image(caca->mlx, 1200, 800);
  memset(background->pixels, 255 , background->width * background->height * sizeof(int));
  mlx_image_to_window(caca->mlx, background, 0, 0);
  mlx_image_to_window(caca->mlx, caca->img, 0, 0);
  julia(f, caca->mlx, caca->img, caca);
  mlx_loop_hook(caca->mlx, &loop_hook, caca);
  mlx_scroll_hook(caca->mlx, &my_scrollhook, caca);
  mlx_loop(caca->mlx);
  free(caca);
  free(f);
  system("leaks a.out"); 
  return (0);
}