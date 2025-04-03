/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:37:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/03 13:01:17 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
** Function checks defines/assigns what type of fractal we will be making.
** Should probably do some more stuff later on
** for now this is a really simple function so we
** can try to render the mandelbrot.
*/

void	establish_fractal_type(t_fractal *fractal, char *str)	//TODO
{
	fractal->name = ft_strdup(str);
	if (fractal->name == NULL)
		exit_program(fractal);
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (correct_input(argc, argv) == false)	//TODO
		return (-1);

	establish_fractal_type(&fractal, argv[1]);
	fractal_init(&fractal);
	fractal_render(&fractal);
//	check_events();				//TODO
	mlx_loop(fractal.mlx_ptr);	
	
	return (0);
}
