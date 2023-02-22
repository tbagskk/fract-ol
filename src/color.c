#include "../fractol.h"

int	get_color(int iter)
{
	t_caca	*caca;
	int		r;
	int		g;
	int		b;

	caca = malloc(sizeof(t_caca));
	if (iter == caca->max_iter)
		return (WHITE);
	r = (iter * 10) % 256;
	g = (iter * 20) % 256;
	b = (iter * 30) % 256;
	free(caca);
	return (r << 16 | g << 8 | b);
}

/*
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
*/