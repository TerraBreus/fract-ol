/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   render.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 18:29:26 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/31 18:50:22 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	assign_pixel_color(int x, int y, t_fractal *fractal) 
{
	t_complex	z;

	z.r = x * fractal->window_map;
	z.i = y * fractal->window_map;	//TODO ((y * window_map) * zoom) + offset
	while (i < fractal->max_i)
	{
		z = sum_compl(sq_compl(z) + c);				//TODO
		if (out_of_bounds(z.r, z.i, fractal->hypotenuse_sq) == true)	//TODO
			put_pixel(fractal->img, x, y, fractal->color_map * i);	//TODO
		i++;
	}
	put_pixel(fractal->img, x, y, MANDELBROT_COLOR); 
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			assign_pixel_color(x, y, fractal->window_map, fractal->color_map);
			y++;
		}
		x++;
	}
	if (mlx_put_image_to_window(fractal->mlx_ptr, \
			fractal->mlx_window, fractal->img.img, 0, 0) == -1)
		exit_program(fractal);
}
