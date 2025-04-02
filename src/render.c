/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   render.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 18:29:26 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/02 17:00:46 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Function not really necessary.
** May be reduced to the if statement
** in which it is called.
** Chose to make function for readibility
*/

static bool	out_of_bounds(double a, double b, double c)
{
	if ((a*a) + (b*b) > (c*c))
		return (true);
	else
		return (false);
}

static void	put_pixel(t_img *img, int x, int y, double color)
{
	char	*dst;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	assign_pixel_color(int x, int y, t_fractal *fractal) 
{
	t_complex	z;
	t_complex	c;
	int		i;

	c.r = (x - WIDTH / 2) * fractal->window_map;
	c.i = (y - HEIGHT / 2) * fractal->window_map;	//TODO ((y * window_map) * zoom) + offset
	z.r = c.r;
	z.i = c.i;
	i = 0;
	while (i < fractal->max_i)
	{
		z = sum_compl(sq_compl(z),  c);	
		if (out_of_bounds(z.r, z.i, fractal->hypotenuse_sq) == true)
		{
			put_pixel(&fractal->img, x, y, fractal->color_map * i);
			return ;
		}
		i++;
	}
	put_pixel(&fractal->img, x, y, MANDELBROT_COLOR); 
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
			assign_pixel_color(x, y, fractal);
			y++;
		}
		x++;
	}
	if (mlx_put_image_to_window(fractal->mlx_ptr, \
			fractal->mlx_window, fractal->img.mlx_img, 0, 0) == -1)
		exit_program(fractal);
}
