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

bool	correct_input(int argc, char **argv)		//TODO Implement julia
{
	if (argc != 2)
	{
		show_usage();
		return (false);
	}

	if ((ft_strncmp(argv[1], "mandelbrot", 11) != 0))
	{
		show_usage();
		return (false);
	}
	return (true);
}
