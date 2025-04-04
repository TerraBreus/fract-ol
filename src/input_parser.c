/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   input_parser.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 15:02:05 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/02 19:40:05 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	show_usage(void)			//TODO implement better usage text
{	
	ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
}

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
	fractal->julia_r = -0.835;
	fractal->julia_i = -0.2321;
	return (true);
}

bool	is_input_parsed(t_fractal *fractal, int argc, char **argv)		//TODO Implement julia and have it parse the fractal. Rename to parse_input as it will parse (if input is correct)
{
	if (argc == 2)
	{
		if ((ft_strncmp(argv[1], "mandelbrot", 11) == 0))
			return (set_mandelbrot(fractal, argv[1]));
	}
	else if (argc == 4)
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			return (set_julia(fractal, argv));
			//TODO Check how to convert parameters
		}
	}
	show_usage();
	return (false);
}
