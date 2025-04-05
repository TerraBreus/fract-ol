/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   events.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/03 13:58:56 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/05 12:49:06 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	keyboard_events(int key, t_fractal *fractal)
{
	if (key == ESCAPE)
		exit_program(fractal, EXIT_SUCCESS);
	else if (key >= 65361 && key <= 65364)
	{
		if (key == ARROW_DOWN)
			fractal->y_offset += 10;
		if (key == ARROW_UP)
			fractal->y_offset -= 10;
		if (key == ARROW_LEFT)
			fractal->x_offset -= 10;
		if (key == ARROW_RIGHT)
			fractal->x_offset += 10;
		fractal_render(fractal);
	}
	else if (key == 114)
	{
		fractal->y_offset = 0.0;
		fractal->x_offset = 0.0;
		fractal->zoom = 1.0;
		fractal_render(fractal);
	}
	return (0);
}

static int	close_on_destroy(t_fractal *fractal)
{
	exit_program(fractal, EXIT_SUCCESS);
	return (0);
}

static int	mouse_events(int key, int x, int y, t_fractal *fractal)
{
	x++;
	y++;
	if (key == 4)
	{
		fractal->zoom *= 0.9;
		fractal_render(fractal);
	}
	if (key == 5)
	{
		fractal->zoom *= 1.1;
		fractal_render(fractal);
	}
	return (0);
}

void	check_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, keyboard_events, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_WINDOW, 1L << 0, close_on_destroy, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_events, fractal);
}
