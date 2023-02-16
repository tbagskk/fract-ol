# include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* img;


void hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int32_t	main(void)
{
	mlx_t* mlx;
	mlx_image_t* img2;
	
	int i = 0;
	int x = 0;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return(EXIT_FAILURE);
	img2 = mlx_new_image(mlx, 512, 512);
	img = mlx_new_image(mlx, 128, 128, 128);
	memset(img2->pixels, 255, img2->width * img2->height * sizeof(int));
	mlx_image_to_window(mlx, img2, 0, 0  );
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
	while (i < 512)
	{
		x = 0;
		while (x < 512)
		{
			
			mlx_put_pixel(img2, x, i, 0x007BE27D);
			x++;
		}
		i++;
	}
	i=0;
	x=0;
	while (i < 128)
	{
		x = 0;
		while (x < 128)
		{
			mlx_put_pixel(img, x, i, 0xFF0000FF);
			
			x++;
		}
		i++;
	}
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);

	mlx_terminate(mlx);
	return (EXIT_SUCCESS);


}