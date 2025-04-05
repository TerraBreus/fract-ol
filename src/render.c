/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zivanov <zivanov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:29:26 by zivanov           #+#    #+#             */
/*   Updated: 2025/04/05 15:58:27 by zivanov          ###   ########.fr       */
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
	if ((a * a) + (b * b) > (c * c))
		return (true);
	else
		return (false);
}

static void	put_pixel(t_img *img, int x, int y, double color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	check_fractal_type(t_fractal *fractal, t_compl *z, t_compl *c)
{
	if (fractal->is_julia == true)
	{
		c->r = fractal->julia_r;
		c->i = fractal->julia_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

static void	assign_pixel_color(int x, int y, t_fractal *fractal)
{
	t_compl	z;
	t_compl	c;
	int			i;

	z.r = (x + fractal->x_offset - WIDTH / 2) * fractal->window_map * fractal->zoom;
	z.i = (y + fractal->y_offset - HEIGHT / 2) * fractal->window_map * fractal->zoom * -1;
	check_fractal_type(fractal, &z, &c);
	i = 0;
	while (i < fractal->max_i)
	{
		z = sum_compl(sq_compl(z), c);
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
		exit_program(fractal, EXIT_FAILURE);
}
