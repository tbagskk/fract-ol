
#include "../fractol.h"


int get_color(int iter)
{
  t_caca *caca;
  caca = malloc(sizeof(t_caca));
  if (iter == caca->max_iter)
    return BLACK;
  int r = (iter * 10) % 256;
  int g = (iter * 20) % 256;
  int b = (iter * 30) % 256;
  return (r << 16 | g << 8 | b);
}


// algo pour mandelbrot trop grand, a decouper






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
  else if (mlx_is_key_down(caca->mlx, MLX_KEY_G))
  {
    caca->x_julia += 0.1;
    julia(f, caca->mlx, caca->img, caca);
  } 	
   else if (mlx_is_key_down(caca->mlx, MLX_KEY_F))
  {
    caca->x_julia -= 0.1;
    julia(f, caca->mlx, caca->img, caca);
  } 	
  
}

void my_scrollhook(double xdelta, double ydelta,void *param)
{
  (void)xdelta;
  t_caca *caca;
  t_fractal *f;
  int x;
  int y;
  caca = malloc(sizeof(t_caca));
  caca = param;
  f = (t_fractal*)malloc(sizeof(t_fractal));
 
 if (ydelta > 0)
 {
  caca->zoom = caca->zoom * 0.80;
  //caca->max_iter += 100;
  mandelbrot(f, caca->mlx, caca->img, caca);
 }
		
  if (ydelta < 0)
	{
    caca->zoom = caca->zoom / 0.80;
    //caca->max_iter -= 100;
    mandelbrot(f, caca->mlx, caca->img, caca);
  }
  mlx_get_mouse_pos(caca->mlx, &x, &y);
  caca->x_julia -= 0.1;
  printf("%d", x);
}

int	main(void)
{
  mlx_image_t* background;
  mlx_image_t* img;
  t_caca *caca;
  t_fractal *f;
  f = (t_fractal*)malloc(sizeof(t_fractal));
  
  caca = malloc(sizeof(t_caca));
  caca->zoom = 10;
  caca->max_iter = 200;
  caca->x = 0;
  caca->y = 0;
  caca->x_julia = 0.8;
  caca->y_julia = 0.285; 


  caca->mlx = mlx_init(1200, 800, "fracol", true);
  caca->img = mlx_new_image(caca->mlx, WIDTH, HEIGHT);
  background = mlx_new_image(caca->mlx, 1200, 800);
  memset(background->pixels, 255 , background->width * background->height * sizeof(int));
  mlx_image_to_window(caca->mlx, background, 0, 0);
  mlx_image_to_window(caca->mlx, caca->img, 0, 0);
  //color_background(background, 'r');
  julia(f, caca->mlx, caca->img, caca);

  mlx_loop_hook(caca->mlx, &loop_hook, caca);
  mlx_scroll_hook(caca->mlx, &my_scrollhook, caca);
  mlx_loop(caca->mlx);
  return (0);
}