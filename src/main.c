/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:37:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/03 15:40:29 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
** Function checks defines/assigns what type of fractal we will be making.
** Should probably do some more stuff later on
** for now this is a really simple function so we
** can try to render the mandelbrot.
*/

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (is_input_parsed(&fractal, argc, argv) == false)	//TODO
		return (-1);

//	fractal_memset()			//TODO (set all values to NULL)
	fractal_init(&fractal);
	fractal_render(&fractal);
	check_events(&fractal);
	mlx_loop(fractal.mlx_ptr);	
	
	return (0);
}
