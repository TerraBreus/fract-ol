/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:37:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/03/31 15:30:39 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (correct_input(argc, argv) == false)	//TODO
		return (-1);

	establish_fractal_type();		//TODO
	
	fractal_init(&fractal);			//TODO
	fractal_render(&fractal);		//TODO
	
	check_events();
	
	return (0);
}
