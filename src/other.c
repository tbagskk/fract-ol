/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:01:57 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/23 08:02:31 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	choose_fractal(int nb, t_caca *caca, t_fractal *f)
{	
	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (nb == 2)
		mandelbrot(f, caca->mlx, caca->img, caca);
	else if (nb == 1)
		julia(f, caca->mlx, caca->img, caca);
	free(f);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int verif_fractal(char *str, t_fractal *f, t_caca *caca)
{
  char *str2;
  int i;
  int j;

  i = 0;
  j = 0;

  if (ft_strcmp(str, "julia") == 0)
	caca->fract = 2;
  else if (ft_strcmp(str, "mandelbrot") == 0)
	caca->fract = 1;
  else
  {
	write(1,"error -> ", 9);
	write(1,"enter : ", 8);
	write(1,"julia or mandelbrot", 19);
	return (0);
  }
  return (1);
}

int verif_ac(int ac, char *str, t_fractal *f, t_caca *caca)
{
	if (ac < 2)
		{
			write(1, "not enough arguments", 20);
			return (0);
		}
		
	else if (ac == 2)
	{
		if (((verif_fractal(str, f, caca)) == 1))
			return (1);
	}
			
	else if (ac > 2)
	{
			write(1, "to many arguments", 17);
			return (0);
	}
	return (0);

}
