/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: zivanov <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/03/31 13:37:43 by zivanov        #+#    #+#                */
/*   Updated: 2025/04/07 14:45:48 by zivanov        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_memset(t_fractal *fractal)
{
	fractal->mlx_ptr = NULL;
	fractal->mlx_window = NULL;
	fractal->name = NULL;
	fractal->img.mlx_img = NULL;
	fractal->img.addr = NULL;
	fractal->max_i = 0;
}

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	fractal_memset(&fractal);
	if (is_input_parsed(&fractal, argc, argv) == false)
	{
		ft_putstr_fd(USAGE, 2);
		return (-1);
	}
	fractal_init(&fractal);
	fractal_render(&fractal);
	check_events(&fractal);
	mlx_loop(fractal.mlx_ptr);
	return (0);
}
