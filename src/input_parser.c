/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   input_parser.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 15:02:05 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/05 13:28:36 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	set_mandelbrot(t_fractal *fractal, char *str)
{
	fractal->name = ft_strdup(str);
	if (fractal->name == NULL)
		exit_program(fractal, EXIT_FAILURE);
	fractal->is_julia = false;
	return (true);
}

static bool	set_julia(t_fractal *fractal, char **argv)
{
	fractal->name = ft_strdup(argv[1]);
	if (fractal->name == NULL)
		exit_program(fractal, EXIT_FAILURE);
	fractal->is_julia = true;
	return (true);
}

bool	is_input_parsed(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 2)
	{
		if ((ft_strncmp(argv[1], "mandelbrot", 11) == 0))
			return (set_mandelbrot(fractal, argv[1]));
		if (ft_strncmp(argv[1], "julia_constants", 16) == 0)
			exit_on_julia_constants();
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
			return (set_julia(fractal, argv));
	}
	else if (argc == 4)
	{
		if ((ft_strncmp(argv[1], "mandelbrot", 11) == 0) \
			&& (ft_strncmp(argv[2], "-i", 3 == 0)))
		{
			fractal->max_i = ft_atoi(argv[3]);
			return (set_mandelbrot(fractal, argv[1]));
		}
	}
	else if (argc == 5)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0 \
			&& ft_strncmp(argv[3], "-i", 3) == 0)
		{
			fractal->max_i = ft_atoi(argv[4]);
			return (set_julia(fractal, argv));
		}
	}
	ft_putstr_fd(USAGE, 2);
	return (false);
}
