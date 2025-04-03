/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   events.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/04/03 13:58:56 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/03 16:06:34 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>	//TODO

int	close_on_escape(int key, t_fractal *fractal)
{
	if (key == ESCAPE)
		exit_program(fractal, EXIT_SUCCESS);
	return (0);
}

int	close_on_destroy(t_fractal *fractal)
{
	exit_program(fractal, EXIT_SUCCESS);
	return (0);
}

void	check_events(t_fractal *fractal)
{
	mlx_key_hook(fractal->mlx_window, close_on_escape, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_WINDOW, 1L << 0, close_on_destroy, fractal);
}
