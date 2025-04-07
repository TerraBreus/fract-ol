/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   input_parser.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 15:02:05 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/07 14:46:17 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	two_arguments(t_fractal *fractal, char **argv)
{
	if ((ft_strncmp(argv[1], "mandelbrot", 11) == 0))
		return (set_mandelbrot(fractal, argv[1]));
	else if (ft_strncmp(argv[1], "julia_constants", 16) == 0)
		exit_on_julia_constants();
	return (false);
}

static bool	three_arguments(t_fractal *fractal, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		return (set_julia(fractal, argv));
	return (false);
}

static bool	four_arguments(t_fractal *fractal, char **argv)
{
	if ((ft_strncmp(argv[1], "mandelbrot", 11) == 0) \
			&& (ft_strncmp(argv[2], "-i", 3 == 0)))
	{
		fractal->max_i = ft_atoi(argv[3]);
		return (set_mandelbrot(fractal, argv[1]));
	}
	return (false);
}

static bool	five_arguments(t_fractal *fractal, char **argv)
{
	if (ft_strncmp(argv[1], "julia", 6) == 0 \
		&& ft_strncmp(argv[3], "-i", 3) == 0)
	{
		fractal->max_i = ft_atoi(argv[4]);
		return (set_julia(fractal, argv));
	}
	return (false);
}

bool	is_input_parsed(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2)
		return (two_arguments(fractal, argv));
	else if (argc == 3)
		return (three_arguments(fractal, argv));
	else if (argc == 4)
		return (four_arguments(fractal, argv));
	else if (argc == 5)
		return (five_arguments(fractal, argv));
	return (false);
}
