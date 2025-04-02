/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:37:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/02 10:34:15 by terramint        ###   ########.fr       */
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

/* Currently under construction
** Phase 1: rendering the initial mandelbrot.
**
*/

//int	main(int argc, char *argv[])
int	main(void)
{
	t_fractal	fractal;

//	if (correct_input(argc, argv) == false)	//TODO
//		return (-1);

//	establish_fractal_type();		//TODO
	
	fractal_init(&fractal);
	fractal_render(&fractal);		//TODO
	
//	check_events();				//TODO
	
	return (0);
}
